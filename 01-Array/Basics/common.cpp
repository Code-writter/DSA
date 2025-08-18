#include<bits/stdc++.h>
using namespace std;
   
int main(){

    vector<int> arr1 = {1, 5, 10, 20, 40, 80};
    vector<int> arr2 = { 6, 7, 20, 80, 100};
    vector<int> arr3 = { 3, 4, 15, 20, 30, 70, 80, 120 }; 


    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < arr1.size() && j < arr2.size() && k < arr3.size()){
        cout<<i<<endl;
        cout<<"Lsdfshd"<<endl;
        if(arr1[i] == arr2[j] == arr3[k]){
            cout<<arr1[i]<<endl;
            break;
        }else if(arr2[j] > arr1[i]){
            i++;
        }
        else if(arr3[k] > arr2[j]){
            j++;
        }
        else{
            k++;
        }
    }



    return 0;
};