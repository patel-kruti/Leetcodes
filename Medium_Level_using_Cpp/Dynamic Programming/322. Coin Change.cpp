// Problem - 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/description/
// Time Complexity - O(n * amount)
// Space Complexity - O(amount)
// Solution - 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) return -1;
        if (amount == 0) return 0;

        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);

        dp[0] = 0; // Base case
        for(int c: coins){ // Itearte over each Coin
            for(int a = c; a <= amount; a++){ // Start from coin value to amount
                if (dp[a - c] != INT_MAX) { // Ensure previous subproblem is solvable
                    dp[a] = min(dp[a], dp[a - c] + 1); // Recurrence relation
                }
            }
        }

        return dp[amount] == INT_MAX ? -1 : dp[amount]; // If amount is not reachable, return -1
    }
};