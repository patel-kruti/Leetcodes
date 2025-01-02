// Problem - 162. Find Peak Element
// Link - https://leetcode.com/problems/find-peak-element/
// Topics - Array, Binary Search
// Time Complexity - O(log n)
// Space Complexity - O(1)
// Solution - 
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while(left < right){
            int mid = (left + right) / 2;

            if(nums[mid] > nums[mid + 1]){ // Peak might lie in left half, including mid
                right = mid;
            } else {
                left = mid + 1; // Peak might lie in right half
            }
        }

        return left;
    }
}; 