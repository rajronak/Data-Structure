#include<iostream>
using namespace std;

bool isPalindrome(string name,int j,int i){

    if(i >= j){
        return true;
    }

    if(name[i] != name[j]){
        return false;
    }
    else{
        isPalindrome(name,--j,++i);
    }
}

int main(){

    string name = "chicha";

    bool ans = isPalindrome(name,name.length()-1,0);

    if(ans){
        cout<<"Name is Palindrome: "<<endl;

    }
    else{
        cout<<"Name is not Palindrome: "<<endl;
    }

}