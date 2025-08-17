#include<bits/stdc++.h>
using namespace std;
   
int main(){

    vector<int> arr = {1, 3, 4, 3, 5};

    for(int i = 0; i<arr.size(); i++){
        // store the element
        int element = abs(arr[i]);
        
        if(arr[element - 1] > 0){
            // mark visited
            arr[element - 1] *= -1;
        }
    }

    for(auto i : arr){
        if(arr[i] < 0){
            cout<<"Duplicated : "<<i <<endl;
        }
    }

    return 0;
};