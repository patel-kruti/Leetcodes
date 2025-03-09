// Problem: 2579. Count Total Number of Colored Cells
// Link: https://leetcode.com/problems/count-total-number-of-colored-cells/
// Topic: Math
// Difficulty: Medium
// Time Complexity: O(1)
// Space Complexity: O(1)
// Solution:
class Solution {
    public:
        long long coloredCells(int n) {
            long long result = 1;
            for(int i = 1; i < n; i++){
                result += 4 * i;
            }
            return result;
        }
    };