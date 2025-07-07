#include <iostream>
#include <string.h>
#include<algorithm>


using namespace std;

void reverseString(char ch[], int len){
    int i = 0; 
    int j = len - 1;
    cout<<j<<endl;
    while(i <= j){
        
        swap(ch[i], ch[j]);
        i++;
        j--;
    }
    cout<<"After Reversed : "<<ch<<endl;
}

int main(){
    char ch [10];

    cin>>ch;
    int len = strlen(ch);
    reverseString(ch, len);
    cout<<"After Reversed inside Main  : " <<ch<<endl;
}