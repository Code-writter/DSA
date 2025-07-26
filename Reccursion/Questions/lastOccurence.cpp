#include<iostream>
#include<string>
#include<vector>
using namespace std;

void firstOccurence(string str, char chToSearch, int index, int &ans){
    // base case
    if(index >= str.length()){
        return;
    }
    // one case
    if(str[index] == chToSearch){
        ans = index;
    }
    // recursion
    firstOccurence(str, chToSearch, index + 1, ans);

}


void reverseTheString(string &str, int startPtr, int endPtr){
    if(startPtr > endPtr){
        return;
    }

    swap(str[startPtr], str[endPtr]);
    reverseTheString(str, startPtr + 1, endPtr - 1);
}


void palindromeCheck(string str, int start, int end, bool &ans){
    if(start > end){
        return;
    }

    if(str[start] == str[end]){
        ans = true;
        palindromeCheck(str, start + 1, end - 1, ans);
    }else{
        ans = false;
        return;
    }
    
}

void printSubArrays(vector<vector<int>> &ansArray, vector<int>arr, int start, int end){
    if(end >= arr.size() - 1){
        return;
    }
    vector<int> temp;
    for(int i = start; i<end; i++){
        temp.push_back(arr[i]);
    }
    ansArray.push_back(temp);
    printSubArrays(ansArray, arr, start, end + 1);
}

void allSubArrays (vector<vector<int>> &ansArray, vector<int> arr, int end){
    if(end >= arr.size() - 1){
        return;
    }

    for(int i = 0; i<arr.size(); i++){
        printSubArrays(ansArray, arr, i, end);
    }
}

int main(){
    string str = "rccar";
    // char chToSearch = 'l';
    // int index = 0;
    // int ans = -1;
    // firstOccurence(str, chToSearch, index, ans);
    // int startPtr = 0;
    // int endPtr = str.length() - 1;
    // reverseTheString(str, startPtr, endPtr);

    // cout<<" After reverse : "<<str<<endl;
    // bool ans = false;
    // palindromeCheck(str, 0, str.size() - 1, ans);

    // if(ans){
    //     cout<<"Palindrom"<<endl;
    // }else{
    //     cout<<"Not"<<endl;
    // }
    vector<int> arr = {1,2,3,4,5,6};
    vector<vector<int>> ansArray;
    int start = 0;
    int end = 0;
    allSubArrays(ansArray,arr, end);


    return 0;
}