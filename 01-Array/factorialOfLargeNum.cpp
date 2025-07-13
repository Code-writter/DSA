#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> addTwoArray(vector<int> arr1, vector <int> arr2){
    int carry = 0;
    int i = arr1.size() - 1;
    int j = arr2.size() - 1;
    vector<int> ans;
    // iterate reverse
    while(i >= 0 && j>= 0){
        int sum = arr1[i] + arr2[j] + carry;
        
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum/10;
        i--; j--;
    }
    // When first array ends
    while(i >= 0){
        int sum = arr1[i] + 0 + carry;
        
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum/10;
        i--;
    }

    while(j>= 0){
        int sum = 0 + arr2[j] + carry;
        
        int digit = sum % 10;
        ans.push_back(digit);
        carry = sum/10;
        j--;
    }
    ans.push_back(carry);
    
    // Remove leading zero if carry is 0
    if (ans.back() == 0) ans.pop_back();

    // Reverse ans to get the correct order
    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {9, 9, 7};
    //  11  2 0 
    vector<int> result = addTwoArray(arr1, arr2);
    for(auto digit : result){
        cout << digit << " ";
    }
    return 0;
};