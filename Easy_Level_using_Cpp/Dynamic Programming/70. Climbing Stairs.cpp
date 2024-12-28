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

// Memoization solution - Memory Limit Exceeded
class Solution {
    private:
    int recursiveSolution(vector<int>dp, int n){
        if (n <= 2){
            return n;
        }
        if(dp[n] == -1){
            dp[n] = recursiveSolution(dp, n-1) + recursiveSolution(dp, n-2);
        }

        return dp[n];
    }
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        vector<int> dp(n+1, -1);
        return recursiveSolution(dp, n);
    }
};

// Recursive Solution - Time Limit Exceeded
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2){
            return n;
        }
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
};

