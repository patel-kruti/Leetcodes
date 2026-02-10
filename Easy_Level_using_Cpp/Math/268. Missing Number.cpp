/*
Problem: 268. Missing Number
Link: https://leetcode.com/problems/missing-number/?envType=problem-list-v2&envId=wv5ww91e
Topics: Array, Bit Manipulation, Math, Sorting, Binary Search
Level: Easy
*/

// Appraoch - Gauss Formula - Math - Time: O(n), Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sumOfNums = (n * (n + 1)) / 2;

        for(int num: nums){
            sumOfNums -= num;
        }

        return sumOfNums;
    }
};

// Approach - More Safer Approach for large number 10^5, 10^6. long long to avoid n and sumOfNums overflow.
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();

        long long sumOfNums = (n * (n + 1)) / 2;

        for(int num: nums){
            sumOfNums -= num;
        }

        return (int)sumOfNums;
    }
};


// Approach 3: Bit Manipultion. No overflow Risk. time: O(n), Space: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xorAll = 0;

        for(int i = 0; i <= n; i++){
            xorAll ^= i;
        }

        for(int num: nums){
            xorAll^= num;
        }

        return xorAll;
    }
};

