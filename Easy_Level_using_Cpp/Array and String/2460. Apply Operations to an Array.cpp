// Problem: 2460. Apply Operations to an Array
// Link: https://leetcode.com/problems/apply-operations-to-an-array/
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Topics: Array, Two Pointers, Simulation
// Solution: 
class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
    
            // Step 1: Merge adjacent Equal numbers
            for(int i = 0; i < n - 1; i++){
                if(nums[i] != 0 && nums[i] == nums[i + 1]){
                    nums[i] *= 2;
                    nums[i + 1] = 0;
                }
            }
    
            // Step 2: Shift Zeros to the right
            int slow = 0, fast = 0;
            while(fast < n){
                if(nums[slow] == 0){
                    while(fast < n && nums[fast] == 0){
                        fast++;
                    }
                    if(fast < n){
                        swap(nums[slow], nums[fast]);
                    }
                }
                slow++;
                fast++;
            }
            return nums;
        }
    };