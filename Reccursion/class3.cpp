#include<iostream>
#include<vector>

using namespace std;

bool isSorted(vector<int> arr, int index){
    if(index > arr.size()){
        return true;
    }

    if(arr[index] > arr[index - 1]){
        isSorted(arr, index + 1);
    }else{
        return false;
    }

}

int binarySearch(vector<int> arr, int start, int end, int target){
    if(start > end) return -1;

    int mid = (start + end) / 2;

    if(arr[mid] == target){
        return mid;
    }

    if(arr[mid] < target){
        return binarySearch(arr, mid + 1, end, target);
    }else{
        return binarySearch(arr, start, mid - 1, target);
    }
}


void subSequences(string strs, string output, int index){
    if(index >= strs.length()){
        cout<< output<<" ";
        return;
    }

    // get the character 
    char ch = strs[index];

    // exclude
    subSequences(strs, output, index + 1);
    // include
    output.push_back(ch);
    subSequences(strs, output, index + 1);


    // NOTE: or we could change the order
    // but then we need to clear the output
    // Include
    output.push_back(ch);
    subSequences(strs, output, index + 1);
    // Exclude
    output.pop_back();
    subSequences(strs, output, index + 1);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5,};
    int index = 1;
    // isSorted(arr, index) ? cout<<"Yes it is Sorted"<<endl : cout<<"No its not sorted"<<endl;
    int start = 0;
    int end = arr.size() - 1;
    int target = 4;
    // binarySearch(arr, start, end, target) ? cout<<"Yes element found "<<endl : cout<<"No element found "<<endl;

    // binarySearch(arr, start, end, target) ? cout << "Yes element found " << endl : cout << "No element found " << endl;

    // int ans = binarySearch(arr, start, end, target);
    // if(ans != -1){
    //     cout<<"Yes : "<<ans<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }

    
    subSequences("Hello", "", 0);

    return 0;
};