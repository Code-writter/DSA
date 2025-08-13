#include<iostream>
#include<vector>
using namespace std;
   
int check(vector<int> arr, vector<int> leftKaSum, vector<int> rightKaSum){

    for(int i = 0; i<arr.size(); i++){
        if(leftKaSum[i] == rightKaSum[i]){
            return arr[i];
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {1, 7, 3, 6, 5, 6};

    // two vector
    vector<int> leftKaSum(arr.size(), 0);
    vector<int> rightKaSum (arr.size(), 0);

    // Pure left ka sum

    for(int i = 1; i < arr.size(); i++){
        leftKaSum[i] = leftKaSum[i - 1] + arr[i - 1];
    }

    // Pure right ka sum
    for(int i = arr.size() - 2; i >= 0; i--){
        rightKaSum[i] = rightKaSum[i + 1] + arr[ i + 1];
    }
    int ans = check(arr, leftKaSum, rightKaSum);
    cout<<"Ans is  : "<<ans<<endl;
    if(ans == -1){
        cout<<"Element not found"<<endl;
    }else{
        cout<<"Element found"<<endl;
    }

    return 0;
};