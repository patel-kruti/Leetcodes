// Problem - 42. Trapping Rain Water
// Link - https://leetcode.com/problems/trapping-rain-water/
// Difficulty - Hard
// Topic - Array, Two Pointers, Stack
// Time Complexity - O(n)
// Space Complexity - O(1)
// Solution - Two Pointers
class Solution {
public:
    int trap(vector<int>& height) {
        int waterTrapped = 0;
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;

        while(left < right){
            if(height[left] < height[right]){
                if(height[left] >= leftMax){
                    leftMax = height[left];
                } else {
                    waterTrapped += leftMax - height[left];
                }
                left++;
            } else {
                if(height[right] >= rightMax){
                    rightMax = height[right];
                } else {
                    waterTrapped += rightMax - height[right];
                }
                right--;
            }
        }
        return waterTrapped;
    }
};