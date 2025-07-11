#include<iostream>
#include<vector>
using namespace std;

void sortArray(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;

    while(start < end){
        if(arr[start] < 0){
            start++;
        }else if(arr[end] > 0){
            end--;
        }else{
            swap(arr[start], arr[end]);
        }
    }

    for(auto a : arr){
        cout<<a<<"  ";
    }
}

int main(){
    vector<int> arr = {4, 6, -2, -5, 3, -1, 0, 2, -3};

    sortArray(arr);
    return 0;
}