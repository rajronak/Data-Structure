// check pallindrome while considering upper and lower case as same

#include<iostream>
using namespace std;
char lowerCase(char ch){     // to convert uppercase into lower case
    if(ch >= 'a' && ch <= 'z'){
        return ch;
    }
    else{
    
    ch = ch - 'A' + 'a';
    return ch;
    }
}
int length(char name[]){   // to find length of name
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++){
        count++;
    }
    return count;
}
int pallindrome(char name[], int size){
    int s = 0;
    int e = size - 1;
    while(s<=e){
        if(lowerCase(name[s]) != (lowerCase(name[e]))){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
int main(){
    char name[20];
    cin>>name;
    cout<<"Your name is pallindrome : "<<pallindrome(name,length(name));

}