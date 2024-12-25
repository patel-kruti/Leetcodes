// Problem - 70. Climbing Stairs
// Link - https://leetcode.com/problems/climbing-stairs/description/
// Topics - Math, Dynamic Programming, Memoization
// Time Complexity:
// Recursive - O(n)
// Iterative - O(n)
// Space Complexity:
// Recursive - O(n) - If memoization
// Iterative - O(n) - If memoization, else O(1)
// Solution --
// Iterative -------------------------------------------
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }

        int first = 1, second = 2;
        for(int i = 3; i <= n; i++){
            int temp = first + second;
            first = second;
            second = temp;
        }

        return second;
    }
};

