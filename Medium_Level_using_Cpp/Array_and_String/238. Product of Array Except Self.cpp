// Problem: 238. Product of Array Except Self
// Link: https://leetcode.com/problems/product-of-array-except-self/description/
// Time Complexity: O(n)
// Space Complexity: O(1)
// Topics: Array, Prefix Sum
// Solution:
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int totalProduct = 1;
        int countZeros = 0;
        int numsLen = nums.size();
        vector<int> answer(numsLen, 0);

        for(int i = 0; i < numsLen; i++){
            if(nums[i] != 0){
                totalProduct *= nums[i];
            } else {
                countZeros++;
            }
        }

        if(countZeros > 1){
            return answer;
        } else if(countZeros == 1){
            for(int i = 0; i < numsLen; i++){
                if(nums[i] != 0){
                    answer[i] = 0;
                } else {
                    answer[i] = totalProduct;
                }
            }
        } else {
            for(int i = 0; i < numsLen; i++){
                if(nums[i] != 0){
                    answer[i] = (totalProduct / nums[i]);
                } else {
                    answer[i] = totalProduct;
                }
            }
        }
        return answer;

    }
};