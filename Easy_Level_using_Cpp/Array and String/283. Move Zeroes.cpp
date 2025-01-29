// Problem :283. Move Zeroes
// Link: https://leetcode.com/problems/move-zeroes/
// Difficulty: Easy
// Topics: Array, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution 1: Using Two Pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1){ // only one element in array
            return;
        }

        int p = 0, c = 1; // pointers: prev and curr
        /* 
        Approach:
        p | c | Action
        1 | 1 | p++ , c++
        1 | 0 | p++ , c++
        0 | 1 | nums[p] = nums[c] , nums[c] = 0, p++
        0 | 0 | c++ unil c < len(nums) && nums[c] == 0
        */
        while(c < nums.size()){
           if(nums[p] != 0){ 
            p++;
            c++;
           } else if(nums[c] != 0){
            nums[p] = nums[c];
            nums[c] = 0;
            p++;
            c++;
           } else {
            while(c < nums.size() && nums[c] == 0){
                c++;
            }
           }
        }

        return;
    }
};