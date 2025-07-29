#include<iostream>
#include<vector>
#include<limits.h>
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


int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    selectionSort(arr);

    for(auto a : arr){
        cout<<a<<"  ";
    }

    return 0;
};