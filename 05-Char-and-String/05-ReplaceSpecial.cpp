#include <iostream>
using namespace std;


void replaceSpecial(char ch[]){
    int index = 0;
    while(ch[index] != '\0'){
        if(ch[index] == '@'){
            ch[index] = ' ';
        }
        index++;
    }

    cout<<"After Replacement : "<<ch;
}

int main(){
    char ch[10];

    cin>>ch;
    replaceSpecial(ch);
}