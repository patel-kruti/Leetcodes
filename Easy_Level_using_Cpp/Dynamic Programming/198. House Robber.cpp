// Problem - 198. House Robber 
// Link - https://leetcode.com/problems/house-robber/description/
// Topics - Dynamic Programming, Array
// Time Complexity - O(n) - Iterate through array once
// Space Complexity - O(1)
// Solution -
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if( n == 1){
            return(nums[0]);
        }
        if(n == 2 ){
            return (max(nums[0], nums[1]));
        }

        int p1 = 0;
        int p2 = 0;

        for(int i=0; i<n; i++){
            int curr = max(p1, p2 + nums[i]);
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};