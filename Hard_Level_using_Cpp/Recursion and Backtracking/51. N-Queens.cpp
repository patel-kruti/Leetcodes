// Problem: 51. N-Queens
// Link: https://leetcode.com/problems/n-queens/description/
// Topics: Array, Backtracking
// Time Complexity: O(n!)
// Space Complexity: O(n) - stack + cols, diag1, diag2
// Solution:
// Without Pruning ---------------------
class Solution {
    private:
    void backtrack(int row, int n, vector<string>& board, unordered_set<int>& cols, unordered_set<int>& diag1, unordered_set<int>& diag2, vector<vector<string>>& result){
        if(row == n){
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(cols.count(col) || diag1.count(row - col) || diag2.count(row + col)){
                continue;
            }
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);

            backtrack(row + 1, n, board, cols, diag1, diag2, result);
            
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
            board[row][col] = '.';
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        unordered_set<int> cols;
        unordered_set<int> diag1;
        unordered_set<int> diag2;

        backtrack(0, n, board, cols, diag1, diag2, result);

        return result;
    }
};