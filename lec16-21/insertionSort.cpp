#include<iostream>
using namespace std;
int main(){
    int temp;
    int arr[5] = {4,9,8,3,10};
    for(int i = 0;i<4;i++){
        for(int j= i; j>= 0;j--){
            temp = arr[j];
            if(arr[j+1] < arr[j]){
                arr[j] = arr[j+1];

            }
            else{
                break;
            }
            arr[j+1] = temp;
        }
    }
    cout<<"sorted array : ";
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}