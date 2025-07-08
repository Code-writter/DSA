#include <iostream>
using namespace std;

string removeDuplicates(string s) {
    string temp = "";
    int index = 0;
    while(index < s.length()){
        // same element
        if( temp.length() > 0 && temp[temp.length() - 1 ] == s[index]){
            temp.pop_back();
        }else{
            // different element 
            temp.push_back(s[index]);
        }
        index++;
    }
    return temp;
}


int main(){

}