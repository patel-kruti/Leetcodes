// Problem : 3417. Zigzag Grid Traversal With Skip
// link : https://leetcode.com/problems/zigzag-grid-traversal-with-skip/submissions/1663142521/
// Topics : Array
// Solution :
class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> ans;
        int skip = 0;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0; i < m; i++){
            if(i%2 == 0){
                for(int j = 0; j < n; j++){
                    if(!skip){
                        ans.push_back(grid[i][j]);
                        skip = 1;
                    } else {
                        skip = 0;
                    }
                }
            } else {
                for(int j = n - 1; j >= 0; j--){
                    if(!skip){
                        ans.push_back(grid[i][j]);
                        skip = 1;
                    } else {
                        skip = 0;
                    }
                }
            }
        }
        return ans;
    }
};
