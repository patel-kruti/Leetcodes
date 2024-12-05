// Problem: 15. 3Sum
// Link: https://leetcode.com/problems/3sum/description/
// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Topics: Array, Two Pointers, Sorting
// Solution: 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        sort(nums.begin(), nums.end());
        int lenNums = nums.size();

        for(int i = 0; i < lenNums - 2; i++){
            if( i > 0 && nums[i] == nums[i - 1]){
                continue;
            }

            int target = -nums[i];
            int left = i + 1;
            int right = lenNums - 1;

            while (left < right){
                int currSum = nums[left] + nums[right];
                
                if (currSum == target){
                    triplets.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    while(left < right && nums[left] == nums[left - 1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right + 1]){
                        right--;
                    }
                }
                else if (currSum < target) {
                    left++;
                }
                else{
                    right--;
                }
            }   
        }
        return triplets;
    }
};