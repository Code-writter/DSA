#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
  

void bubbleSort(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = 0; j<arr.size() - i - 1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j + 1]);
            }
        }
    }
} 


void selectionSort(vector<int> &arr){
    for(int i = 0; i< arr.size(); i++){
        int minIndex = i;
        for(int j = i; j<arr.size(); j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


void insertionSort(vector<int> &arr){
    // Skip the 0th index 
    for(int i = 1; i<arr.size(); i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            // Swapping till the elements are greater than the key
            arr[j + 1] = arr[j];
            j--;
        }
        // Insertion
        arr[j + 1] = key;
    }
}




bool comparator(int &a, int &b){
    return a < b; // This will sort the increasing Order
    return a > b; // This will sort the Decreasing Order
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};

    sort(arr.begin(), arr.end(), comparator);

    for(auto a : arr){
        cout<<a<<"  ";
    }

    return 0;
}