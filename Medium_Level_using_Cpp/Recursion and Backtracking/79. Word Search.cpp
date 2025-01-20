// Problem : 79. Word Search
// Link : https://leetcode.com/problems/word-search/description/
// Topics : Array, String, Backtracking, Depth-First Search, Matrix
// Time Complexity : O(M × N × 4^L)
// Space Complexity : O(L) - Length of Word
// Solution :
class Solution {
private:
    bool dfs(vector<vector<char>>& board, string word, int index, int r, int c){
        if(index == word.size()) return true;
        if(r < 0 || r >= board.size() 
        || c < 0 || c >= board[0].size() 
        || board[r][c] != word[index]) 
        return false;

        char temp = board[r][c];
        board[r][c] = '#';

        bool found = dfs(board, word, index + 1, r + 1, c) ||
                     dfs(board, word, index + 1, r - 1, c) ||
                     dfs(board, word, index + 1, r, c + 1) ||
                     dfs(board, word, index + 1, r, c - 1);
        board[r][c] = temp;

        return found; 
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == word[0] && dfs(board, word, 0, r, c)){
                    return true;
                }
            }
        }
        return false;
    }
};