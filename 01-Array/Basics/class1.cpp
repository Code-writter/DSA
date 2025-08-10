#include<iostream>
#include<algorithm>
using namespace std;
   
int main(){

    int arr[5] = {10, 20, 30 , 40 ,50 };
    int size = 5;
    // // Access
    int lastElement = arr[size - 1];

    for(int i = size - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }

    arr[0] = lastElement;

    for(int i = 0; i<size; i++){
        cout<<arr[i]<<"  ";
    }



    // cout<<arr[0]<<endl;
    // cout<<arr[1]<<endl;

    // All elements

    // for(int i = 0; i < size ; i++){
    //     cout<<arr[i]<<"  ";
    // }

    // // mutliply 2 on all elements
    // cout<<endl;
    // int j = 0;
    // while( j < size){
    //     cout<<arr[j] * 2 <<"  ";
    //     j++;
    // }
    // cout<<endl;
    // int k = 0;

    // do{
    //     cout<<arr[k]*3<<"  ";
    //     k++;
    // }while(k < size);


    int brr[1] = {1};
    int ans = 0;

    for(int i = 0; i<1; i++){
        ans = ans ^ brr[i];
    }
    cout<<endl;
    cout<<"Extra element : "<<ans<<endl;


    // ! Print all pairs

    // int arr[4] = {1, 2, 3, 4};

    // for(int i = 0; i<4; i++){
    //     for(int j = i; j<4; j++){
    //         for(int k = j; k<4; k++){
    //             cout<<"{ "<<arr[i]<<", "<<arr[j]<<", "<< arr[k] <<" }" <<"  ";
    //         }
    //     }
    //     cout<<endl;
    // }

    // Put all the zeros in the front
    // int arr[6] = {1, 0, 1, 1, 1, 0};
    // int zeros = 0;
    // int ones = 0;

    // for(int i = 0; i<6; i++){
    //     if(arr[i] == 0){
    //         zeros++;
    //     }else{
    //         ones++;
    //     }
    // }
    // int k= 0;
    // while(zeros != 0){
    //     arr[k] = 0;
    //     zeros--;
    //     k++;
    // }
    // while(ones != 0){
    //     arr[k] = 1;
    //     ones--;
    //     k++;
    // }

    // for(int i = 0; i<6; i++){
    //     cout<<arr[i]<<"  ";
    // }

    // * two pointers

    // int startPointer = 0;
    // int endPointer = 5;

    // while(startPointer < endPointer){
    //     if(arr[endPointer] == 0 && arr[startPointer] == 1){
    //         swap(arr[startPointer], arr[endPointer]);
    //         // startPointer++;
    //         // endPointer--;

    //     }else if( arr[endPointer] == 1) {
    //         endPointer--;
    //     }else{
    //         startPointer++;
    //     }
    // }

    // for(int i = 0; i<6; i++){
    //     cout<<arr[i]<<"  ";
    // }


    return 0;
};