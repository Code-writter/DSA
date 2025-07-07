#include <iostream>
#include <string.h>

using namespace std;

int getLength(char ch[], int size){
    int count = 0;

    for(int i = 0; i<size; i++){
        if(ch[i] == '\0'){
            return count;
        }else{
            count++;
        }
    }
    return count;
}

int main(){
    char ch[10];

    cin.getline(ch, 10);
    int size = 10;
    // int count = getLength(ch, size);

    // cout << "Lenght of Char array  " << count<<endl;

    // STL

    cout<<"Length using STL : "<<strlen(ch)<<endl;
}