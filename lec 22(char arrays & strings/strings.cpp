#include<iostream>
using namespace std;
void reverse(char name[], int length){
    int s = 0;
    int e = length - 1;
    while(s<=e){
        swap(name[s++],name[e--]);
    }
}
int length(char ch[]){
    int count = 0;
    for(int i = 0; ch[i] != '\0'; i++ ){
        count++;
    }
    return count;
}
int main(){
    char name[20];
    cin>>name;
    cout<<"length of name : "<<length(name)<<endl;
    int len = length(name);
    cout<<"reverse of name ";
    reverse(name,len);
    cout<<name;
}