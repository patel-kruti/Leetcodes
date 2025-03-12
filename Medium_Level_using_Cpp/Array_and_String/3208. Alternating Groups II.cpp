// Problem: 3208. Alternating Groups II
// Link: https://leetcode.com/problems/alternating-groups-ii/
// Topic: Array, Sliding Window
// Difficulty: Medium
// Time Complexity: O(nk)
// Space Complexity: O(n)
// Solution:
class Solution {
    public:
        int numberOfAlternatingGroups(vector<int>& colors, int k) {
            int n = colors.size();
            int totalAlternatingGroups = 0;
            vector<int> arrangedColors(n);
    
            int breakPoint = -1;
            for(int i = 0; i < n - 1; i++){
                if(colors[i] == colors[i + 1]){
                    breakPoint = i;
                    break;
                }
            }
    
            // If no breakpoint is found, keep original order
            if (breakPoint == -1) {
                if(colors[0] != colors[n - 1]){
                    return n;
                } else {
                    arrangedColors = colors;
                }
            } else {
                int index = 0;
                for(int i = breakPoint + 1; i < n; i++){
                    arrangedColors[index++] = colors[i];
                }
                for(int i = 0; i <= breakPoint; i++){
                    arrangedColors[index++] = colors[i];
                }
            }
    
            for(int i = 0; i <= n - k; i++){
                int flag = 0;
                for(int j = i; j < i + k - 1; j++){
                    if(arrangedColors[j] == arrangedColors[j + 1]){
                        flag = 1;
                        break;
                    }
                }
                if(!flag) totalAlternatingGroups++;
            }
            
            return totalAlternatingGroups;
        }
    };