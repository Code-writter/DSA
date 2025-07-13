#include<iostream>
#include <vector>
using namespace std;
   

int main(){

    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;

            int row = matrix.size();
            int col = matrix[0].size();
            int elements = row*col;

            int startingRow = 0;
            int endingCol = col - 1;
            int endingRow = row - 1;
            int startingCol = 0;

            int count = 0;
            while(count < elements){
                // print starting row
                for(int i = startingRow ; i<= endingCol && count<elements ; i++){
                    ans.push_back(matrix[startingRow][i]);
                    count++;
                }
                startingRow++;

                // print ending col
                for(int i = startingRow; i<= endingRow && count<elements; i++){
                    ans.push_back(matrix[i][endingCol]);
                    count++;
                }
                endingCol--;

                // print ending row
                for(int i = endingCol; i >= startingCol && count<elements ; i--){
                    ans.push_back(matrix[endingRow][i]);
                    count++;
                }
                endingRow--;
                // Print starting col
                for(int i = endingRow; i >= startingRow && count<elements ; i--){
                    ans.push_back(matrix[i][startingCol]);
                    count++;
                }
                startingCol++;


            }

            return ans;
        }
    };
    return 0;
};