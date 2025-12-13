    #include <vector>
    #include <algorithm> // For swap
    using namespace std;

    class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int size = matrix.size();
    
            // Step 1: Vertical Flip (Reverse rows)
            // Swap elements symmetrically along the horizontal midline of the matrix.
            // This effectively flips the matrix upside down.
            for (int row = 0; row < size / 2; ++row) {
                for (int col = 0; col < size; ++col) {
                    swap(matrix[row][col], matrix[size - 1 - row][col]);
                }
            }
    
            // Step 2: Diagonal Flip (Transpose)
            // Swap symmetric elements across the main diagonal (top-left to bottom-right).
            // This completes the 90-degree clockwise rotation.
            for (int i = 0; i < size; ++i) {
                for (int j = 0; j < i; ++j) { // Iterate only for the lower triangle to avoid double swapping
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }
    };