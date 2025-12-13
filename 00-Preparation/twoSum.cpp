
#include <iostream>
#include<unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// vector<int> twoSum(vector<int> arr, int target){
//     unordered_map<int, int> numMap;

//     for(int i = 0; i < arr.size(); i++){
//         int currentEle = arr[i];
//         int diff = target - currentEle;
 
//         if(numMap.count(diff)){
//             // here numMap = {diff : index}, ie key value pair so we are 
//             // returning the value of the kye ie index of the elment
//             return {numMap[diff], i};
//         }

//         // If not found, add the current number and its index to the map
//         numMap[currentEle] = i;
//     }
//     // If no solution is found, return an empty vector
//     cout << "No two sum solution found." << endl;
//     return {};
// }

// vector < int > twoSumApp(vector <int> arr, int target){
//     sort(arr.begin(), arr.end());
//     int i = 0;
//     int j = arr.size() - 1;
//     while(i < j){
//         if(arr[i] + arr[j] == target){
//             return {arr[i], arr[j]};
//         }
//         if(arr[i] + arr[j] > target){
//             j--;
//         }else{
//             i--;
//         }
//     }
//     return {};
// }

// int main(){
//     vector<int> arr = {3, 2, 4};
//     int target = 6;
//     vector<int> ans = twoSumApp(arr, target);
//     if(ans.empty()){
//         cout << "No two sum solution found." << endl;
//         return 0;
//     }
//     for(auto a : ans ){
//         cout << a << " ";
//     }

// }

    double signFunc(vector<int>& nums){
        double prod = 1;
        for(int i = 0; i<nums.size(); i++){
            prod = prod * nums[i];
        }
        return prod;
    }
int main(){
    vector<int> nums = {1,28,-91,-62,-36,-1,-84,-90,-92,61,6,-58,-60,2,51,-15,-18,-81,87,84,100,-84,-13,-87,-33,72,-72,-59,-79,28,-69,-97,-93,17,67,11,-12,19,5,42,-85,71,-77,-82,26,-58,-51,-14,63,-85,-86,66,47,57,-86,-25,-75,59,-17,-71,89,-78,-42,30,39,61,-96,-30,-29,-92,-90,69,20,65,32,92,44,-71,-18,87,-86,23,-96,-21,-49,-96,-98,35,-11,-1,81,-48,68,5,75,57,-30,-7,32,86,-29,-86,-61,45,-31,-93,-26,-9,86,57,-52,75,68,-58,14,27,-94,47,-38,-44,75,-83,21,-83,43,62,74,97,78,43,54,28,64,-19,-89,88,68,18,-96,-83,-25,-71,88,-84,-24,-61,72,-90,-56,29,46,56,51,16,66,-2,65,-95,16,51,42,61,99,89,-93,59,-99,69,26,-61,21,41,40,-4,-49,3,-96,57,65,72,-41,-77,-4,61,71,-88,21,-95,38,64,92,0,-63};
    double ans = signFunc(nums);

    cout <<"Answer is : "<<ans<<endl;
}
