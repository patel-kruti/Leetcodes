# Problem: 49. Group Anagrams
# Link: https://leetcode.com/problems/group-anagrams/description/
# Time Complexity: O(n * k log k)
# Space Complexity: O(n * k)
# Topics: Array, Hash Table, String, Sorting
# Solution:
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}

        for s in strs:
            key = ''.join(sorted(s))
            if key not in anagrams:
                anagrams[key] = []
                
            anagrams[key].append(s)

        return list(anagrams.values())