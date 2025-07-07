#include <iostream>
#include <string.h>
using namespace std;


bool checkPalindrom(char ch[]){
    int i = 0;
    int j = strlen(ch) - 1;

    while( i <= j){
        if(ch[i] == ch[j]){
            i++;
            j--;
        }else{
            return false;
        }
    }
    
    return true;
}

int main(){
    char ch[10];

    cin>>ch;
    bool ans = checkPalindrom(ch);
    if(ans){
        cout << "It is Palindorm"<<endl;
    }else{
        cout<<"Not a palindrom"<<endl;
    }
}