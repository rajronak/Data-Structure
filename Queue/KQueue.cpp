#include<iostream>
using namespace std;
class KQueue{
    public:
        int *arr;
        int *next;
        int *front;
        int *rear;
        int freespot;
        int n;
        int k;

    KQueue(int k,int n){
        freespot = 0;
        this -> k = k;
        this -> n = n;
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k ; i++){
            front[i] = rear[i] = -1;
        }
        next = new int[n];
        for(int i = 0; i< n ; i++){
            if(i == n-1){
                next[i] = -1;
            }
            else{
                next[i] = i+1;
            }
        }

    }

    void enqueue(int data, int qn){
        // check overflow
        if(freespot == -1){
            cout<<"Queue is overflowed: "<<endl;
            return;
        }
        int index = freespot;
        // updating freespot
        freespot = next[index];

        // if inseting first element in that queue

        if(front[qn - 1] == -1){
            front[qn - 1] = index;
        }
        else{
            // linking prev rear to new spot
            next[rear[qn - 1]] = index;
        }
        // indicating that place is filled
        next[index] = -1;
        // updating rear to place data is going
        rear[qn - 1] = index;
        // insertion of data
        arr[index] = data;
    }


    int dequeue(int qn){
        // check underflow
        if(front[qn - 1] == -1){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        int index = front[qn -1];
        front[qn - 1] = next[index];
        
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }
};

int main(){
    KQueue q(3,8);
    q.enqueue(10, 1);
    
    q.enqueue(15,1);
    q.enqueue(20, 2);
    q.enqueue(25,1);

    cout << q.dequeue(1) << endl;
    cout << q.dequeue(2) << endl;
    cout << q.dequeue(1) << endl;
    cout << q.dequeue(1) << endl;

    cout << q.dequeue(1) << endl;

}