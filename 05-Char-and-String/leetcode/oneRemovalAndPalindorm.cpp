#include <iostream>
using namespace std;

bool checkPalindrom(string s, int i, int j){
    while ( i<=j )
    {
        if(s[i] != s[j]){
            return false;
        }else{
            i++;
            j--;
        }
    }
    return true;    
}

bool isPalindrom(string s){
    int i = 0;
    int j = s.length() - 1;

    while( i > j){
        // check till its palindrom     
        if(s[i] == s[j]){
            i--;
            j++;
        }else{
            // Here we removed on and check again
            bool leftAns = checkPalindrom(s, i - 1, i);
            bool rightAns = checkPalindrom(s, i, i + 1);
        }
    }
}

int main(){
    string s;
    bool ans = isPalindrom(s);
}