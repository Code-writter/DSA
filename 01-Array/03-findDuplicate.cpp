#include<iostream>
#include<vector>
using namespace std;
   
int markVisited(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        if(arr[i] > 0){
            return arr[i];
        }
        else{
            // got to the place and mark the visited
            arr[arr[i]] = -1;
        }
    }
    return -1;
}

// With Loop 
int getDuplicateToTheFirst(vector<int> arr){
    while(arr[0] != arr[arr[0]]){
        swap(arr[0], arr[arr[0]]);
    }
    return arr[0];
}

int main(){
    vector<int> arr = {3, 1, 3, 4, 2};

    int ans = getDuplicateToTheFirst(arr);
    cout<<"Duplicate Number is : "<<ans<<endl;
    return 0;
};