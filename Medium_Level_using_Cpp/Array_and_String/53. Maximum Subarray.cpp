// Problem - 53. Maximum Subarray
// Link: https://leetcode.com/problems/maximum-subarray/
// Topics: Array, Divide and Conquer, Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution: Kadane's Algorithm
class Solution {
public:
// Using Kadane's Algorithm - O(n)
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for(int i = 0; i < nums.size(); i++){
            currSum += nums[i];
            if(currSum > maxSum){
                maxSum = currSum;
            }
            if(currSum < 0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};
// Approach 2 
// Solution: Divide and Conquer - O(nlogn)
class Solution {
        public: 
        int maxSubArray(vector<int>& nums) {
            return maxSubArray(nums, 0, nums.size()-1);
        }
        int maxSubArray(vector<int>& nums, int left, int right){
            if(left == right){
                return nums[left];
            }
            int mid = left + (right - left) / 2;
            int leftSum = maxSubArray(nums, left, mid);
            int rightSum = maxSubArray(nums, mid+1, right);
            int crossSum = crossSumArray(nums, left, mid, right);
            return max(max(leftSum, rightSum), crossSum);
        }
        int crossSumArray(vector<int>& nums, int left, int mid, int right){
            int leftSum = INT_MIN;
            int rightSum = INT_MIN;
            int sum = 0;
            for(int i = mid; i >= left; i--){
                sum += nums[i];
                leftSum = max(leftSum, sum);
            }
            sum = 0;
            for(int i = mid+1; i <= right; i++){
                sum += nums[i];
                rightSum = max(rightSum, sum);
            }
            return leftSum + rightSum;
        }
};
