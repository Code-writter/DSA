#include<iostream>
#include<vector>

using namespace std;


// int firstOccurence(vector<int> arr, int target){
//     int start = 0;
//     int end = arr.size() - 1;   
//     int mid = (start + end)/2;
//     int ans = 0;
//     while(start <= end){
//         if(arr[mid] == target){
//             ans = mid;
//             end = mid - 1;
//         }else if(target > arr[mid]){
//             start = mid + 1;
//         }else{
//             end = mid - 1;
//         }
//         mid = (start + end)/2;
//     }
//     return ans;
// }

int missingElement(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = (start + end)/2;
    int ans = 0;
    while(start <= end){
        int difference = arr[mid] - mid;
        if(difference == 1){
            // right search
            start = mid + 1;
        }
        else{
            ans = mid;
            end = mid - 1;
        }
        mid = (start + end)/2;
    }
    return ans + 1;
}


int main(){

    vector<int> arr = {1,2,3,4,5, 7,8, 9};
    int ans = missingElement(arr);
    cout<<"Missing Element is : "<<ans<<endl;
    return 0;
};