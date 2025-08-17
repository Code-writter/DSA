#include <iostream>
#include<algorithm>
#include<vector>

using namespace std;
   
int main(){
    vector<int> arr = {1, 3, 5, 2, 4, 7, 0};

    // sort(arr.begin(), arr.end());

    // for(int i = 0; i<arr.size(); i++){
    //     if(arr[i] != i){
    //         cout<<"Missing Element : "<<i<<endl;
    //     }
    // }

    // ! Xor method

    int ans = 0;
    
    for(int i = 0; i<arr.size(); i++){
        ans = ans^arr[i];
    }
    
    for(int i = 0; i<=arr.size(); i++){
        ans = ans^i;
    }

    cout<<"Missing element is : "<<ans<<endl;

    return 0;
};