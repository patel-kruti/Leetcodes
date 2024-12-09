// Problem: 3. Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
// Time Complexity: O(n)
// Space Complexity: O(k) - Size of character set - max O(26)
// Topics: Hash Table, String, Sliding Window
// Solution: 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndex;
        int maxLength = 0;
        int start = 0;

        for(int end = 0; end < s.length(); end++){
            if(charIndex.find(s[end]) != charIndex.end() && charIndex[s[end]] >= start){
                start = charIndex[s[end]] + 1;
            }
            charIndex[s[end]] = end;
            maxLength = max(maxLength, end - start + 1);
        }

        return maxLength;
    }
};