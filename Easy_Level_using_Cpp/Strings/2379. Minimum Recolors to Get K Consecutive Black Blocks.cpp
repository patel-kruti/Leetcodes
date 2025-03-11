// Problem: 2379. Minimum Recolors to Get K Consecutive Black Blocks
// Link: https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/
// Topic: Strings, Sliding Window
// Difficulty: Easy
// Time Complexity: O(n)
// Space Complexity: O(1)
// Solution:
class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int len = blocks.length();
            int minRecolors = len;
            for(int i = 0; i <= len - k; i++){
                int countW = 0;
                for(int j = i; j < i + k; j++){
                    if(blocks[j] == 'W')
                        countW++;
                }
                if(countW < minRecolors){
                    minRecolors = countW;
                }
            }
    
            return minRecolors;
        }
    };