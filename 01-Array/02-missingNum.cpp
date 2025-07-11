#include<iostream>
#include <vector>
#include<algorithm>
using namespace std;
int findMissing(vector<int> arr){
    int ans = 0; 
    // 0^a = a
    for(int i = 0; i<arr.size(); i++ ){
        ans = ans^arr[i]; 

    }
    for(int i = 0; i<arr.size(); i++){
        ans = ans^i + 1;

    }

    return ans;
}


int main(){
    vector<int> arr = {3, 0, 1, 4, 5};
    int ans = findMissing(arr);

    cout<<"Misssing NUm is : "<<ans<<endl;
}