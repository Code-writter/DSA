#include<iostream>
using namespace std;
   
int fibbo(int num){
    if(num == 0){
        return 0;
    }
    if(num == 1){
        return 1;
    }

    return fibbo(num - 1) + fibbo(num - 2); 
}

void printArr(int arr[], int &size){

    if(size == 0){
        cout<<arr[size]<<"  ";
        return;
    }
    cout<<arr[size]<<"  ";
    size--;
    printArr(arr, size);

}


int main(){
    int num = 8;
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int size = 8;
    printArr(arr, size);
    // int ans = fibbo(num);
    // cout<<"Ans is : "<<ans;
    return 0;
};