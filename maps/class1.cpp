#include<iostream>
#include <unordered_map>
using namespace std;
   
int main(){

    unordered_map<char , int> mp;
    string str;
    cout<<"Enter string : ";
    cin>>str;

    for(int i = 0; i<str.size(); i++){
        mp[str[i]]++;
    }

    for(auto i : mp){
        cout<<i.first << " - "<<i.second<<endl;
    }


    return 0;
};