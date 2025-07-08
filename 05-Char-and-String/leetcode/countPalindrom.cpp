#include <iostream>
using namespace std;

int checkPalindrom(string s, int i, int j){
   int count = 0;
    while (i >= 0 && j <= s.length() - 1 && s[i] == s[j]){
        count++;
        i--;
        j++;
    }
    return count;
}

int countPalindrom(string s){
    int totalCount = 0;
    for(int center = 0; center <= s.length() - 1; center++){
        int oddCheck = checkPalindrom( s, center, center);
        int evenCheck = checkPalindrom(s, center, center + 1);

        totalCount = totalCount + oddCheck + evenCheck;
    }
    return totalCount;
}

int main(){
    string s;
    cin >> s;
    int ans = countPalindrom(s);

    cout<<"Total count of String is : "<<ans<<endl;

}