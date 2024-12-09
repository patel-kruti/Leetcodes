# Problem: 3. Longest Substring Without Repeating Characters
# Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# Time Complexity: O(n)
# Space Complexity: O(k) - Size of character set- O(26) max
# Topics: Hash Table, String, Sliding Window
# Solution:

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        chIndex = {}
        maxLen = 0
        start = 0

        for end in range(0, len(s)):
            if s[end] in chIndex and chIndex[s[end]] >= start:
                start = chIndex[s[end]] + 1
            chIndex[s[end]] = end
            maxLen = max(maxLen, end - start + 1)

        return maxLen