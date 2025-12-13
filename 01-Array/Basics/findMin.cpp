#include<bits/stdc++.h>
using namespace std;
   
void minInArray(vector<int> arr){
    int minElement = INT_MAX;

    for(int i = 0; i<arr.size(); i++){
        if( minElement > arr[i]){
            minElement = arr[i];
        }
    }
    cout<<"Min Element is : "<<minElement<<endl;
}

void maxInArray(vector<int> arr){
    int maxElement = INT_MIN;

    for(int i = 0; i<arr.size(); i++){
        if(maxElement < arr[i]){
            maxElement = arr[i];
        }
    }
    cout<<"Max element in array is : "<<maxElement<<endl;
}

void minInMatrix(vector<vector<int>> matrix){
    int minElement = INT_MAX;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(minElement > matrix[i][j]){
                minElement = matrix[i][j];
            }
        }
    }
    cout<<"Min in matrix ; "<<minElement<<endl;
}

void searchInMatrix(vector<vector<int>> matrix, int target){
    int ans = -1;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            if(matrix[i][j] == target){
                ans = matrix[i][j];
            }
        }
    }

    if(ans == -1){
        cout<<"element not found"<<endl;
    }else{
        cout<<"Element found"<<endl;
    }
}

void transpose(vector<vector<int>> matrix){

    for(int i = 0; i<matrix.size(); i++){
        for(int j = i; j < matrix[0].size(); j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    cout<<"Printing Transpose"<<endl;
    for(int i = 0; i<matrix.size(); i++){
        for(int j = 0; j<matrix[0].size(); j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;
    }
}


int main(){
    // vector<int> arr = {2};

    // maxInArray(arr);
    // minInArray(arr);

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    // searchInMatrix(matrix, 0);
    transpose(matrix);
    return 0;
};