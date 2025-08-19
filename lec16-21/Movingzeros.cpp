#include<iostream>
using namespace std;

void zeroes(int arr[], int m) {
    int s = 0, e = 0; 
    while (e < m) {
        if (arr[e] != 0) {
            swap(arr[s++], arr[e++]);
        } else {
            e++;
        }
    }
}

int main() {
    int arr[5] = {4, 0, 0, 5, 0};
    zeroes(arr, 5);   
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << " ";
    }
}
