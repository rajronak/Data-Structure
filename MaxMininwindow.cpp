#include<iostream>
#include<queue>
using namespace std;
int maxminsum(int arr[], int k, int n){
    deque<int> maxi;
    deque<int> mini;
    int sum = 0;
    //traversing first K window
    for(int i = 0; i < k; i++){

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

    }
    sum += arr[maxi.front()] + arr[mini.front()];
    // traversering other windows

    for(int i = k ; i < n; i++){
        //deletion 
        if(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }
        if(!mini.empty() && i - mini.front() >= k ){
            mini.pop_front();
        }

        //addition

        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){
            maxi.pop_back();
        }
        while(!mini.empty() && arr[mini.back()] >= arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;

}
int main(){
    int arr[7] = {2,5,-1,7,-3,-1,-2};
    int k = 4;
    int ans = maxminsum(arr,k,7);
    cout<<"The sum is : "<<ans<<endl;
    return 0;

}