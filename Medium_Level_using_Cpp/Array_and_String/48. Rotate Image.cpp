// Problem: 48. Rotate Image
// Link: https://leetcode.com/problems/rotate-image/description/
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Topics: Array, Math, Matrix
// Solution:
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix - Swap (i,j) with (j,i) - O(n^2)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse the matrix - O(n^2) - As reversing each row takes O(n)
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};