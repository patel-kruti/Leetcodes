# Problem - 125. Valid Palindrome
# Topics: Two Pointers, String
# Link - https://leetcode.com/problems/valid-palindrome/description/
# Runtime 7 ms Beats 81.48% Analyze Complexity Memory 17.81 MB Beats 28.04%
# Time Complexity: O(n + m2)
# Space Complexity: O(m)
# Solution : 

class Solution:
    def isPalindrome(self, s: str) -> bool:
        actualString = ""
        for c in s:
            if c.isalnum():
                actualString += c.lower()
                
        lenC = len(actualString)
        for i in range(0, int(lenC/2)):
            if actualString[i] != actualString[lenC - i - 1]:
                return False

        return True
    
# Optimum Approach
# Time: O(n)
# Space: O(n)
# Solution:
class Solution:
    def isPalindrome(self, s: str) -> bool:
        filtered_chars = [c.lower() for c in s if c.isalnum()]
        return filtered_chars == filtered_chars[::-1]
