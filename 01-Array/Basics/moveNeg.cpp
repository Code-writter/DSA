#include<bits/stdc++.h>
using namespace std;
   
int main(){
    vector<int> arr = {1, 3, 4, 2, 3};

    // // Method 1
    // sort(arr.begin(), arr.end());

    // for(int i = 1; i<arr.size() ; i++){
    //     if(arr[i] == arr[i - 1]){
    //         cout<<"Duplicate : "<<arr[i]<<endl;
    //     }
    // }
    
    // Method 2

    while(arr[0] != arr[arr[0]]){
        swap(arr[0], arr[arr[0]]);
    }

    cout<<"Duplicate element ; "<<arr[0]<<endl;

    return 0;
};