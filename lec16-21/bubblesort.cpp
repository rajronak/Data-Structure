#include <iostream>
using namespace std;

int main() {
    int arr[6] = {10, 1, 7, 6, 14, 9};
    int n = 6;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int k = 0; k < n; k++) {
        cout << arr[k] << " ";
    }
    cout << endl;
}
