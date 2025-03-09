// Problem: 2965. Find Missing and Repeated Values
// Link: https://leetcode.com/problems/find-missing-and-repeated-values/
// Topic: Array, Hash Table, Math, Matrix
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution 1:

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int visitedSize = (n * n) + 1;
            vector<int> visited(visitedSize, 0);
            vector<int> ans(2);
    
            for(int row = 0; row < n; row++){
                for(int col = 0; col < n; col++){
                    if(!visited[grid[row][col]]){ 
                        visited[grid[row][col]] = 1;
                    } else {
                        ans[0] = grid[row][col];
                    }
                }
            }
    
            for(int i = 1; i < visitedSize; i++){
                if(!visited[i]){
                    ans[1] = i;
                }
            }
    
            return ans;
        }
    };

// Solution 2:
class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            int n = grid.size();
            int totalElements = n * n;
            unordered_set<int> seen;
            int sumActual = 0, sumOfAllElements = (totalElements * (totalElements + 1)) /2;
            int repeated = -1;
    
            for(int row = 0; row < n; row++){
                for(int col = 0; col < n; col++){
                    int currNum = grid[row][col];
                    if(seen.count(currNum)){
                        repeated = currNum;
                    } else {
                        seen.insert(currNum);
                        sumActual += currNum;
                    }
                }
            }
    
            int missing = sumOfAllElements - sumActual;
    
            return {repeated, missing};
        }
    };