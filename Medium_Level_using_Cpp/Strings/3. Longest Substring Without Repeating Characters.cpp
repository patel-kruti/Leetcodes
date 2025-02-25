// Problem : 3. Longest Substring Without Repeating Characters
// Link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty : Medium
// Time Complexity : O(n)
// Space Complexity : O(n)
// Topics : Sliding Window, Hash Map, String
// Solution 1 : Sliding Window
class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            unordered_map<char, int> umap;
            int left = 0, result = 0;
            for(int right = 0; right < s.length(); right++){
                if (umap.find(s[right]) != umap.end() && umap[s[right]] >= left){
                    left = umap[s[right]] + 1;
                }
                umap[s[right]] = right;
                result = max(result, right - left + 1);
            }
           
            return result;
        }
    };