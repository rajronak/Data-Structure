#include<iostream>
using namespace std;

void saydigit(string arr[], int val) {
    // base case
    if (val == 0) {
        return;
    }

    int digit = val % 10;
    saydigit(arr, val / 10);   // recursive call
    
    cout << arr[digit] << " ";
}

int main() {
    string arrN[10] = {"zero", "one", "two", "three", "four", "five", 
                       "six", "seven", "eight", "nine"};
    int n;
    cin >> n;

    if (n == 0) {
        cout << "zero";
    } else {
        saydigit(arrN, n);
    }
}
