// Problem: 54. Spiral Matrix
// Link: https://leetcode.com/problems/spiral-matrix/
// Topic: Array, Matrix, Simulation
// Difficulty: Medium
// Time Complexity: O(m*n)
// Space Complexity: O(1)
// Solution: Simulation
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) return result;

        int top = 0, bottom = matrix.size() - 1;
        int left = 0, right = matrix[0].size() - 1;

        while(top <= bottom && left <= right){
            // Move Left -> Right
            for(int i = left; i <= right; i++){
                result.push_back(matrix[top][i]);
            }
            top++;

            // Move Top -> Bottom
            for(int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }
            right--;

            // Move Right -> Left
            if(top <= bottom){
                for(int i = right; i >= left; i--){
                    result.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Move Bottom -> Top
            if(left <= right){
                for(int i = bottom; i >= top; i--){
                    result.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return result;
    }
};