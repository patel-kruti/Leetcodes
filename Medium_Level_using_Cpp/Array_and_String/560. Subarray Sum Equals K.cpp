// Problem : 560. Subarray Sum Equals K
// Link : https://leetcode.com/problems/subarray-sum-equals-k/
// Topic : Array, Hash Map
// Difficulty : Medium
// Time Complexity : O(n)
// Space Complexity : O(n)
// Solution : Using Hash Map
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumFreq;
        prefixSumFreq[0] = 1;
        int result = 0, currSum = 0;

        for(int num: nums){
            currSum += num;
            if(prefixSumFreq.find(currSum - k) != prefixSumFreq.end()){
                result += prefixSumFreq[currSum - k];
            }
            prefixSumFreq[currSum]++;
        }
        return result;
    }
};