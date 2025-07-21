

#include<iostream>
#include<vector>

using namespace std;

void even(int arr[], int size, int index, vector<int>& ans){
    if(index > size){
        return;
    }

    if(arr[index] % 2 == 0){
        ans.push_back(arr[index]);
    }

    return even(arr, size, index + 1, ans);
}

void doubleTheArray(int arr[], int size, int index){
    if(index > size){
        return;
    }

    arr[index] *= 2;

    doubleTheArray(arr, size, index + 1);

    for(int i = 0; i<=size; i++){
        cout<<arr[i]<<"  ";
    }
    return;
}


int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    doubleTheArray(arr, size - 1, 0);
    for (auto i : ans){
        cout<<i<<"  ";
    }
    return 0;
};