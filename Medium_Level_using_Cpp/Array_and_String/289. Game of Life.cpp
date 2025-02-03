// Problem : 289. Game of Life
// Link : https://leetcode.com/problems/game-of-life/
// Topic : Array, In-place, Matrix, Simulation
// Difficulty : Medium
// Time Complexity : O(m*n)
// Space Complexity : O(1)
// Solution : In-place
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        vector<int> directions = {-1, 0, 1};

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){

                int liveNeigh = 0;

                for(int dr: directions){
                    for(int dc: directions){
                        if(dr == 0 && dc == 0) continue;
                        int nr = r + dr, nc = c + dc;
                        if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && abs(board[nr][nc]) == 1){
                            liveNeigh++;
                        }
                    }
                }

                if(board[r][c] == 1 && (liveNeigh < 2 || liveNeigh > 3)){
                    board[r][c] = -1;
                }

                if(board[r][c] == 0 && liveNeigh == 3){
                    board[r][c] = 2;
                }
            }
        }

        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(board[r][c] == -1) board[r][c] = 0;
                if(board[r][c] == 2) board[r][c] = 1;
            }
        }
    }
};