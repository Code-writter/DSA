#include<iostream>
using namespace std;


void convertUpparCase(char ch[]){
    int index = 0;


    while(ch[index] != '\0'){

        // Note : I did mistake Here 
        char currentEle = ch[index];

        // Checking if the element is in lower case or not
        if(currentEle >= 'a' && currentEle <='z'){
            ch[index] = currentEle - 'a' + 'A';
        }
        index++;
    }

    cout<< "After uppar case : "<<ch<<endl;

}


void convertLowerCase(char ch[]){
    int index = 0;

    while(ch[index] != '\0'){

        // Note : I did mistake Here 
        char currentEle = ch[index];
        
        // Checking if the element is in Uppar case or not
        if(currentEle >= 'A' && currentEle <='Z'){
            ch[index] = currentEle - 'A' + 'a';
        }
        index++;
    }

    cout<< "After Lower case : "<<ch<<endl;

}

int main(){
    char ch[10];
    cin>>ch;
    // convertUpparCase(ch);
    convertLowerCase(ch);
}