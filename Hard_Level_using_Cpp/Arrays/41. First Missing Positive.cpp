// Problem - 41. First Missing Positive
// Link - https://leetcode.com/problems/first-missing-positive/
// Difficulty - Hard
// Topic - Array, Hash Map
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution - Using Cyclic Sort
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Cyclic Sort - Ignore negative, graeter than n and duplicates
        // Try to swap the number at its correct position if possible
        for(int i = 0; i < n; i++){
            while(nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first missing Positive
        for(int i = 0; i < n; i++){
            if(nums[i] != i + 1){
                return i + 1;
            }
        }

        return n + 1; // If all the n elements are present
    }
};