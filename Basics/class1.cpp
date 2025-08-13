#include<iostream>
using namespace std;
   
int main(){
    // // Looping statements 
    int arr[10]={1,0,2,1,2,0,2,1,1,0};
    int count1=0;
    int count2=0;
    int count0=0;
    
    int size=10;

    // for(int i=0; i<size; i++){
    //     for(int j=i; j>0; j--){
    //        int right_sum = 0;
    //        int right_sum =+ arr[j];
    //     }
    //     for(int k=i; k<size; k++){
    //         int left_sum = 0;
    //         int left_sum =+ arr[k];
    //     }
    //     if(right_sum == left_sum){
    //         return arr[i];
    //     }

    // }
    for(int i = 0; i<size; i++){
        if(arr[i]==0){
            count0++;

        }else if(arr[i]==1){
            count1++;
        }else{
            count2++;
        }
    }

    
    while(count0--){
        arr[i]=0;
    }
    while(count1--){
        arr[i]=1;
    }
    while(count2--){
        arr[i]=2;
    }


    return 0;
};