#include <iostream>
using namespace std;

int main(){
    char ch[100];

    cin >> ch;

    cout << ch;

    // Lets see the ASCII value of Null Character

    for(int i = 0; i < 10; i++){
        cout << "Charcter at "<< i<< " "<<ch[i]<<" "<<endl;
    }

    char temp = ch[3];

    // Explicit type conversion
    int value = (int)temp;

    cout<<value<<endl;


    // NOTE: to get whole line

    cin.getline(ch, 10);
    cout <<ch;
}