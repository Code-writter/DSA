#include<iostream>
#include <vector>
using namespace std;
   
int searchNearlySorted(vector<int> arr, int target){
    int start = 0;
    int end = arr.size()-1;
    int mid = start + (end - start)/2;

    while(start<= end){
        if(arr[mid] == target){
            return mid;
        }
        else if(mid - 1 > 0 && arr[mid - 1] == target){
            return mid - 1;
        }
        else if(mid + 1 < arr.size() - 1 && arr[mid + 1] == target){
            return mid + 1;
        }
        else if(arr[mid] < target){
            start = mid + 2;
        }else{
            end = mid - 2;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int findOddOccurringElement(vector<int> arr){
    int start = 0;
    int end = arr.size() - 1;
    int mid = start + (end - start)/2;

    while(start <= end){
        // single element case
        if(start == end){
            return start;
        }

        if(mid & 1){
            // Odd
            if(mid - 1 >= 0 && arr[mid] == arr[mid - 1]){
                // Right 
                start = mid + 1;
            }else{
                // Left
                end = mid - 1;
            }
        }else{
            // Even
            if( mid + 1 < arr.size() - 1 && arr[mid] == arr[mid + 1]){
                // Right
                start = mid + 2;
            }else{
                // Left
                end = mid;
            }
        }
        mid = start + (end - start)/2;
    }
}

void bubbleSort(vector<int> arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j < arr.size() - i; j++){
            if(mid + )
        }
    }
}

int main(){
    vector<int>arr =  { 1, 4, 4, 5, 5, 2, 2, 7, 7, 2,2 , 1,1, 3, 3};

    int index = findOddOccurringElement(arr);
    cout<<"Element found in : "<<index<<endl;
    return 0;
};