/*
Problem: 303. Range Sum Query - Immutable
Link: https://leetcode.com/problems/range-sum-query-immutable/?envType=problem-list-v2&envId=wv5ww91e
Topics: Array, Prefix Sum, Math
Level: Easy
*/

// Naive Solution - W/o prefix Sum, SPace: O(n), Time: O(nq)
class NumArray {
    private:
    vector<int> globalNum;

public:
    NumArray(vector<int>& nums) {
        globalNum = nums;
    }
    
    int sumRange(int left, int right) {
        int sumOfArray = 0;
        for(int i = left; i <= right; i++){
            sumOfArray += globalNum[i];
        }

        return sumOfArray;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

// Prefix Sum
class NumArray {
    private:
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1);
        prefixSum[0] = 0;

        for(int i = 0; i < nums.size(); i++){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
