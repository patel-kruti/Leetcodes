// Problem : 2161. Partition Array According to Given Pivot
// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Topics: Array, Two Pointers, Simulation
// Solution:
class Solution {
    public:
        vector<int> pivotArray(vector<int>& nums, int pivot) {
            int n = nums.size();
            vector<int> result(n);
    
            int left = 0;
            for(auto num: nums){
                if(num < pivot){
                    result[left++] = num;
                }
            }
    
            int right = n - 1;
            for(int i = n - 1; i >= 0; i--){
                if(nums[i] > pivot){
                    result[right--] = nums[i];
                }
            }
    
            for(int i = left; i <= right; i++){
                result[i] = pivot;
            }
    
            return result;
        }
    };
