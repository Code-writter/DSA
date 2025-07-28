#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;


void printMatrix(int arr[][3], int numberOfRows, int numberOfCols){
    for(int row = 0; row < numberOfRows; row++){
        for(int col = 0; col < numberOfCols; col++){
            cout<<arr[row][col]<<"  ";
        }
        cout<<endl;
    }
}

bool search(int arr[][3], int target, int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = 0; j < col; j++){
            if(arr[i][j] == target) return true;
        }
    }

    return false;
}

int maxElement(int arr[][3], int row, int col){
    int maxEle = INT_MIN;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            maxEle = max(maxEle, arr[i][j]);
        }
    }
    return maxEle;
}
int minElement(int arr[][3], int row, int col){
    int maxEle = INT_MAX;
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            maxEle = min(maxEle, arr[i][j]);
        }
    }
    return maxEle;
}

void rowWiseSum(int arr[3][3], int row, int col){
    for(int i = 0; i<row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum = sum + arr[i][j];
        }
        cout<<"Sum : "<<sum<<endl;
    }
}
void colWiseSum(int arr[3][3], int row, int col){
    for(int i = 0; i<row; i++){
        int sum = 0;
        for(int j = 0; j < col; j++){
            sum = sum + arr[j][i];
        }
        cout<<"Sum : "<<sum<<endl;
    }
}

int diagonalSum(int arr[][3], int row, int col){
    int digSum = 0;
    for(int i = 0; i<row; i++){
        digSum = digSum + arr[i][i];
    }
    return digSum;
}

void diagonalPrint(int arr[][3], int row, int col){

    for(int i = 0; i<row; i++){
        cout<< arr[i][i]<<"  ";
    }

}

void otherDiagonal(int arr[3][3], int row, int col){
    for(int i = 0, j = row - 1; i<row, j>=0; i++, j--){
        cout<<arr[i][j]<<"  ";
    }
}

void transpose(int arr[][3], int row, int col){
    for(int i = 0; i<row; i++){
        for(int j = i; j<col; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }

}

int main(){
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int row = 3;
    int col = 3;

    vector<vector<int>> matrix;

    vector<int> arr(3, -1);

    printMatrix(arr, row, col);
    // if(search(arr, 77, row, col)){
    //     cout<<"Found "<<endl;
    // }else{
    //     cout<<"Not found"<<endl;
    // }
    // cout<<"Max element = "<<maxElement(arr, row, col)<<endl;
    // cout<<"Max element = "<<minElement(arr, row, col)<<endl;

    cout<<endl;

    // int sum = diagonalSum(arr, row, col);
    // cout<<"Diagonal Sum is : "<<sum<<endl;
    transpose(arr, row, col);
    for(int i = 0; i<row; i++){
        for(int j = 0; j<col; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }

    return 0;
}