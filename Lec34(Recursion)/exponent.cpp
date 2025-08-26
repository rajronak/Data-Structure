#include<iostream>
using namespace std;

int Power(int a,int b){

    if(b==0){
        return 1;
    }

    if(b==1)
    return a;

    if(b%2==0){
        int ans;
        ans = Power(a,b/2);
        return ans * ans;
    }

    else{
        int ans;
        ans = Power(a,b/2);
        return a * ans*ans;
    }
}

int main(){

    int a,b;
    cin>>a>>b;

    int ans = Power(a,b);

    cout<<ans<<endl;
}