
#include <iostream>
#include<unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int longestSubStr(string s){

    // edge cases 
    if(s.length() == 0 || s.length() == 1){
        return s.length();
    }


    int longest = 0;

    int left = 0;
    int right = 0;
    vector<bool> check(256, false);

    while(right < s.length()){

        if(check[s[right]]){
            
        }
    }


}


int main(){

    string s;

    int ans = longestSubStr(s);

}