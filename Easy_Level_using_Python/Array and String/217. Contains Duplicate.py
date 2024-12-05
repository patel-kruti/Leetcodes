# Problem: 217. Contains Duplicate
# Link: https://leetcode.com/problems/contains-duplicate/description/
# Time Complexity: O(n)
# Space Complexity: O(n)
# Topics: Array, Hash Table, Sorting
# Solution:
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        if(len(nums) == 1):
            return False

        seen = set()

        for num in nums:
            if num in seen:
                return True
            seen.add(num)

        return False
        
        
        
        
        