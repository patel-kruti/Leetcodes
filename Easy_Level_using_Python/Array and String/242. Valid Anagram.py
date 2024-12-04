# Problem: 242. Valid Anagram
# Link: https://leetcode.com/problems/valid-anagram/description/
# Time Complexity: O(n)
# Space Complexity: O(1)
# Topics: Hash Table, String, Sorting
# Solution:
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if(len(s) != len(t)):
            return False
        count = [0] * 26
        for c in s:
            count[ord(c) - ord('a')] += 1
        for c in t:
            count[ord(c) - ord('a')] -= 1

        return all(c == 0 for c in count)