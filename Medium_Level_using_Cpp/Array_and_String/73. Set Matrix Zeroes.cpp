// Problem : 73. Set Matrix Zeroes
// Link: https://leetcode.com/problems/set-matrix-zeroes/
// Topics: Array, Matrix
// Time Complexity: O(m*n)
// Space Complexity: O(1)
// Solution:
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool firstRow = false, firstCol = false;

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(matrix[r][c] == 0){
                    if(r == 0) firstRow = true;
                    if(c == 0) firstCol = true;
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        for(int r = 1; r < rows; r++){
            for(int c = 1; c < cols; c++){
                if(matrix[r][0] == 0 || matrix[0][c] == 0){
                    matrix[r][c] = 0;
                }
            }
        }

        if(firstRow){
            for(int c = 0; c < cols; c++){
                matrix[0][c] = 0;
            }
        }

        if(firstCol){
            for(int r = 0; r < rows; r++){
                matrix[r][0] = 0;
            }
        }        
    }
};