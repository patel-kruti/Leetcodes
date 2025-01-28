// Problem : 26. Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Topics: Array, Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution 1: Using Two Pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 1){
            return 1;
        } 

        int k = 1; // unique nums counter : result
        int p = 0, c = 1; // previous and current nums pointers
        while(c < nums.size()){
            if(nums[p] != nums[c]){ // if current is unique
                p++;                // increament the prev pointer
                nums[p] = nums[c]; // replace the prev (duplicate value) with current unique value 
                k++; // found a unique element
            }
            c++; // move to next num in array
        }

        return k; 
    }
};