#include<iostream>
using namespace std;

class Node{

    public: 
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
    }

    ~Node(){
        if(next!= NULL){
            delete next;
            next = NULL;
        }
    }
};

void InsertAtStart(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void InsertAtEnd(Node* &head,Node* &tail,int data){
    if(tail == NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(data);
        tail -> next = temp;
        temp -> prev = tail;
        tail = temp;
    }
}

void InsertAtPosition(Node* &head,Node* &tail,int position,int data){
    if(position == 1){
        InsertAtStart(head,tail,data);
        return;
    }

    else{
        int cnt = 1;
        Node* Curr = new Node(data);
        Node* temp = head;
        while(cnt < position - 1){
            temp = temp-> next;
            cnt++;     
        }
        temp -> next -> prev = Curr;
        Curr -> next = temp -> next;
        temp -> next = Curr;
        Curr -> prev = temp;

        if(Curr -> next == NULL){
            tail = Curr;
        }
    }

}
void Delete(Node* &head,Node* &tail,int position){

    if(position == 1){
        Node* temp = head;

        head = temp -> next;
        head -> prev = NULL;
        temp -> next = NULL;
        delete temp;
        return;
    }
    int cnt = 1;
    Node* previ = NULL;
    Node* Curr = head;
    while(cnt < position - 1){
        cnt++;
        previ = Curr;
        Curr = Curr -> next;
    }
    previ -> next = Curr -> next;
    Curr -> next -> prev = previ;
    Curr -> next = NULL;
    Curr -> prev = NULL;
    delete Curr;
    if(previ -> next == NULL){
        tail = previ;
    }
}
void print(Node* head){
    while(head != NULL){
        cout<<head -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(23);
    Node* head = node1;
    Node* tail = node1;

    

    InsertAtStart(head,tail,25);
    InsertAtStart(head,tail,22);
    InsertAtStart(head,tail,17);
    InsertAtStart(head,tail,29);
    

    InsertAtEnd(head,tail,45);
    

    InsertAtPosition(head,tail,6,34);
    print(head);
    Delete(head,tail,7);
    print(head);
    cout<<"head : "<<head -> data<<endl;
    cout<<"tail : "<<tail -> data<<endl;



    return 0;
}