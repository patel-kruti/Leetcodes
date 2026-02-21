/*
Problem: 75. Sort Colors
Link: http://leetcode.com/problems/sort-colors/description/
Topics: Array, Two Pointers
Difficulty: Medium
Brute Force: Counting Sort (2-pass) T: O(n), S: O(1), 3 Var, Naive: T: O(nlogn), Space: O(1) or O(log n), considers n numbers
Three way partitioning Algorithm used to optimize Quick Sort
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Single-Pass Algorithm: The Dutch Natinal Flag Algorithm - O(n) Time, O(1) Space

        int n = nums.size();
        int left = 0, mid = 0, right = n - 1;

        while(mid <= right){
            if(nums[mid] == 0){
                swap(nums[mid], nums[left]);
                left++;
                mid++;
            } else if(nums[mid] == 2){
                swap(nums[mid], nums[right]);
                right--;
            } else {
                mid++;
            }
        }
    }
};
