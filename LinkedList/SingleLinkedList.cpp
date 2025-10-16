#include<iostream>
using namespace std;

class Node{
       public:
       int data;
       Node* Next;

    Node(int value){
        this->data = value;
        this->Next = NULL;
    }   
    public:
    
};

void InsertatHead(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{

        Node* temp = new Node(data);
        temp -> Next = head;
        head = temp;
    }
}


void InsertAtTail(Node* &tail,Node* &head,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{

        Node* temp = new Node(data);
        tail -> Next = temp;
        tail = temp;
    }
}


void InsertAtPosition(int position,Node* &head,Node* &tail,int data){

    int cnt = 1;
    if(position == 1){
        InsertatHead(head,tail,data);
        return;
    }
    Node* temp = head;
    while(cnt < position){
        temp = temp -> Next;
        cnt++;
    }
    if(temp->Next == NULL){
        InsertAtTail(tail,head,data);
        return;
    }

    temp->data = data;


}

void print(Node* head){

    while(head != NULL){
        
        cout<<head->data<<" ";
        
        head = head->Next;
    }
    cout<<endl;

}

bool FlyodsDetection(Node* &head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        slow = slow -> Next;
        fast = fast -> Next;
        if(fast != NULL){
            fast = fast -> Next;
        }
        if(slow == fast){
            return true;
        }
    }
    return false;
}

Node* PositionOfCycle(Node* head){
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        slow = slow -> Next;
        fast = fast -> Next;
        if(fast != NULL){
            fast = fast -> Next;
        }
        if(slow == fast){
            slow = head;
            break;
        }
    }
    while(slow != fast){
        slow = slow -> Next;
        fast = fast -> Next;
    }
    return slow;
}

void DeleteAtPosition(Node* &head,Node* &tail,int position){
    if(position == 1){
        Node* temp = head;
        head = head -> Next;
        temp -> Next = NULL;
        delete temp;
    }
    else{

    Node* current = head;
    Node* prev = NULL;

    int cnt = 1;
    while(cnt < position){
        prev = current;
        current = current -> Next;
        cnt++;
    }
    prev -> Next = current -> Next;
    current -> Next = NULL;
    if(prev -> Next == NULL){
        tail = prev;
    }
    }
    
}
Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = PositionOfCycle(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> Next != startOfLoop) {
        temp = temp -> Next;
    } 

    temp -> Next = NULL;
    return head;
}
void reverse(Node* &head,Node* &tail){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr!= NULL){
        forward = curr -> Next;
        curr -> Next = prev;
        prev = curr;
        curr = forward;
    }
    tail = head;
    head = prev;
}

int main(){
    Node* node1 = new Node(15);
    // cout<<node1->data<<endl<<node1->Next;
    Node* head = node1;
    Node* tail = node1;
    print(head);

    InsertatHead(head,tail,17);
    InsertatHead(head,tail,22);
    InsertatHead(head,tail,77);
    print(head);


    InsertAtTail(tail,head,45);
    print(head);

    InsertAtPosition(1,head,tail,25);
    print(head);

    DeleteAtPosition(head,tail,6);
    print(head);

    tail -> Next = head -> Next;

    // reverse(head,tail);
    // print(head);
    if(FlyodsDetection(head)){
        cout<<" Cycle detected : "<<endl;
    }
    else{
        cout<<" NO Cycle detected : "<<endl;
    }

    Node* temp = PositionOfCycle(head);
    cout<<" Loop present at "<<temp -> data<<endl;
    
    // cout<<head -> data<<endl;
    // cout<<tail -> data<<endl;

}