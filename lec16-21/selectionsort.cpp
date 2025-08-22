#include<iostream>
using namespace std;

int main(){
    int arr[5] = {3,7,5,9,6};
    for(int i =0;i<5;i++){
        int min = arr[i];
        for(int j = i+1; j<5; j++){
            if (arr[i] > arr[j])
            {
                int k = arr[j];
                arr[j] = arr[i];
                arr[i] = k;
            }
            
        }
    }
    for (int k = 0; k < 5; k++)
    {
        cout<<arr[k]<<" ";
    }
    
}