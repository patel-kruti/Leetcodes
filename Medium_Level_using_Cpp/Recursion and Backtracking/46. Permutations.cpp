// Problem : 46. Permutations
// Link : https://leetcode.com/problems/permutations/description/
// Topics : Array, Backtracking
// Time Complexity : O(n X n!) - n! - number of permutations, O(n) - time to copy permutations into result
// Space Complexity : O(n) - depth of recursion stack
// Solution :
class Solution {
private:
    vector<vector<int>> result;

    void backtrack(int start, vector<int>& nums){
        // Base case: If all integers are used then add that permutations
        if(start == nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); i++){
            swap(nums[start], nums[i]); // Swap current element with nums[start]
            backtrack(start + 1, nums); // recurse
            swap(nums[start], nums[i]); // Swap back the nums
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0, nums);
        return result;
    }
};

