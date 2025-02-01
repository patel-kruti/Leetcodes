// Problem - 724. Find Pivot Index
// Link: https://leetcode.com/problems/find-pivot-index/
// Topics: Array, Prefix Sum
// Time Complexity: O(n)
// Sapce Complexity: O(1)
// Solution:
// 1. Calculate the sum of the array.
// 2. Traverse the array and keep track of the left sum and right sum.
// 3. If left sum is equal to right sum then return the index.
// 4. Otherwise return -1.
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int leftSum = 0;
        int rightSum = 0;

        for(int i = 0; i < n; i++){
            rightSum += nums[i];
        }
       
        for(int i = 0; i < n; i++){
            if(i > 0){
                leftSum += nums[i - 1];
            }
            rightSum -= nums[i];
            if(leftSum == rightSum){
                return i;
            }
        }
        return -1;
    }
};
