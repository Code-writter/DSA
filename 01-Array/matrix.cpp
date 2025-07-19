#include<iostream>
#include<vector>

using namespace std;

vector<int> sphiralMatrix(vector<vector<int>> matrix){
    vector<int> sphiral; 
    int row = matrix.size();
    int col = matrix[0].size();
    int totalEle = row * col;

    int startingRow = 0;
    int endingColumn = col - 1;  
    int endingRow = row - 1;
    int startingColumn = 0;
    int count = 0;
    
    while(count < totalEle){
        //  Mistake 1
        for(int i = startingColumn; i<=endingColumn && count < totalEle; i++){
            cout<<matrix[startingColumn][i];
            count++;
        }
        startingRow++;

        for(int i = startingRow ; i<= endingRow && count < totalEle; i++){
            cout<<matrix[i][endingColumn];
            count++;
        }
        // Mistake 2
        endingColumn--;
        for(int i = endingColumn; i >= startingColumn && count < totalEle; i--){
            cout<<matrix[endingRow][i];
            count++;
        }
        endingRow--;
        for(int i = endingRow; i>=startingRow && count < totalEle; i--){
            cout<<matrix[i][startingColumn];
            count++;
        }
        startingColumn++;
    }

    return sphiral;
}

   
int main(){
    
    vector<vector<int>> matrix = {  {1, 2, 3},
                                    {4, 5, 6},
                                    {7, 8, 9},};



    // for(int i = 0; i<matrix.size(); i++){
    //     for(int j = 0; j < matrix[0].size(); j++){
    //         cout<<matrix[i][0]<<"  ";
    //     }
    //     cout<<endl;
    // }
    sphiralMatrix(matrix);
    return 0;
};