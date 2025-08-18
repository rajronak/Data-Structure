// Book allocation problem ---> in this we have to allocate books in such a manner that no books are left and each
// student atleast gets one book
#include <iostream>
using namespace std;
bool istruepossible(int arr[], int mid, int size, int students) // checking wether the mid is a possible soln
{
    int Studentcount = 1;
    int pageSum = 0;
    for (int i = 0; i < size; i++)
    {
        if (pageSum + arr[i] <= mid)   // adding pages so that can be assigned to students
        {
            pageSum += arr[i];
        }
        else
        {
            Studentcount++;                     // if pages added are more than mid it means we have to increase
                                                // -> student count and start assigning to next student
            if (Studentcount > students || arr[i] > mid)          
            {
                return false;
            }
            pageSum = arr[i];
        }
    }
    return true;
}
int main()
{
    int ans = -1;
    int s = 0;
    int size;
    cout << "enter size" << endl;
    cin >> size;
    int arr[size];
    for (int j = 0; j < size; j++)
    {
        cout << "enter value of " << j << " index" << endl;
        cin >> arr[j];
    }
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    int e = sum;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (istruepossible(arr, mid, size, 2))
        {
            ans = mid;
            e = mid - 1;
            
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    cout << ans;
    return 0;
}