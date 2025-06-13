// Problem : 3423. Maximum Difference Between Adjacent Elements in a Circular Array
// Link : https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/submissions/1663120741/
// Topics : Array
// Solution : 
class Solution {
    private:
        int abs(int num){
            if (num < 0){
                return -1 * num;
            }
            return num;
        }
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = abs(nums[nums.size() - 1] - nums[0]);
        int diff = 0;
        for(int i = 1; i < nums.size(); i++){
            diff = abs(nums[i - 1] - nums[i]); 
            if(maxDiff < diff){
                maxDiff = diff;
            } 
        }

        return maxDiff;
    }
};
