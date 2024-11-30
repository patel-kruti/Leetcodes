# Problem: 14. Longest Common Prefix
# Link: https://leetcode.com/problems/longest-common-prefix/description/
# Time Complexity: O(n.m)
# Space Complexity: O(1)
# Topics: String, Trie
# Solution:
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if (len(strs) == 0):
            return ""
        for i in range(0, len(strs[0])):
            c = strs[0][i]
            for j in range(1, len(strs)):
                if(i >= len(strs[j]) or c != strs[j][i]):
                    return strs[0][:i]
        return strs[0]