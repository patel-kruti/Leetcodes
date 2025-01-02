// Problem - 33. Search in Rotated Sorted Array
// Link - https://leetcode.com/problems/search-in-rotated-sorted-array/description/
// Topics - Array, Binary Search
// Time Complexity - O(log n)
// Space Complexity - O(1)
// Solution - 
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(nums[mid] == target){
                return mid; // Target found
            }

            // Check if left side is sorted
            if(nums[left] <= nums[mid]){
                if(nums[left] <= target && target < nums[mid]){ // Search left side
                    right = mid - 1;
                } else {
                    left = mid + 1; // Search right side
                }
            } else {
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1; // Search right side
                } else {
                    right = mid - 1; // Search Left side
                }
            }
        }
        return -1; // Target not found
    }
};
