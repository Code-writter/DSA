#include<iostream>
#include<vector>

using namespace std;
   
int main(){

    // int arr[10] = {};
    // vector<int> arr = {1,2, 0, 0 ,1, 2, 0, 1, 2};
    int arr[9] = {1,2, 0, 0 ,1, 2, 0, 1, 2};

    // // count method
    // int zeros = 0;
    // int ones = 0;
    // int twos = 0;

    // for (int i = 0; i<9; i++){
    //     if(arr[i] == 0){
    //         zeros++;
    //     }else if(arr[i] == 1){
    //         ones++;
    //     }else{
    //         twos++;
    //     }
    // }
    // int k = 0;
    // while(zeros--){
    //     arr[k] = 0;
    //     k++;
    // }
    // while(ones--){
    //     arr[k] = 1;
    //     k++;
    // }
    // while(twos--){
    //     arr[k] = 2;
    //     k++;
    // }

    // for(int i = 0; i<9; i++){
    //     cout<<arr[i]<<"  ";
    // }

    // three pointer 
    int zeroKaPointer = 0;
    int oneKaPointer = 0;
    int twoKaPointer = 8;


    while(oneKaPointer <= twoKaPointer){
        if(arr[oneKaPointer] == 0){
            swap(arr[oneKaPointer], arr[zeroKaPointer]);
            oneKaPointer++;
            zeroKaPointer++;
        }else if(arr[oneKaPointer] == 1){
            oneKaPointer++;
        }else{
            // arr[oneKaPointer] == 2
            swap(arr[oneKaPointer], arr[twoKaPointer]);
            twoKaPointer--;
        }
    }

    for(int i = 0; i<9; i++){
        cout<<arr[i]<<"  ";
    }

    return 0;
};