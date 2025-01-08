// Problem : 39. Combination Sum
// Link : https://leetcode.com/problems/combination-sum/
// Topics : Array, recursion, Backtracking
// Time Complexity : O(2^T * k) -> k = average size of valid combination
// Space Complexity : O(T) -> T = target/minCandidate
// Solution :
class Solution {
    void backtrack(vector<vector<int>>& result, vector<int> path, int target, vector<int>& candidates, int index){
        if(target == 0){
            result.push_back(path);
        } 
        
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) continue;
            path.push_back(candidates[i]);
            backtrack(result, path, target - candidates[i], candidates, i);
            path.pop_back();
        }
        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        backtrack(result, {}, target, candidates, 0);
        return result;
    }
};