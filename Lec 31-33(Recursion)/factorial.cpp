#include<iostream>
using namespace std;

int factorial(int n) {
    // base condition
    if (n == 0 || n == 1)
        return 1;

    return n * factorial(n - 1);
}

int main() {
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans;
    return 0;
}
