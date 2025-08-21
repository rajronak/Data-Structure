#include<iostream>
using namespace std;

bool Binary(int arr[], int s,int e, int key){
    if(s>e)
    return false;

    int mid = (s+e)/2;

    if(arr[mid] == key){
        return true;
    }

    if(arr[mid] < key){
        return Binary(arr,mid+1,e,key);
    }
    else{
        return Binary(arr,s,mid-1,key);
    }
}
int main(){

    int arr[5] = {2,4,6,8,9};
    int key = 11;

    bool ans = Binary(arr,0,4,key);
    if(ans){
        cout<<"Found"<<endl;

    }

    else{
        cout<<"not found"<<endl;
    }
}