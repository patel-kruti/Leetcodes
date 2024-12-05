# Problem: 15. 3Sum
# Link: https://leetcode.com/problems/3sum/description/
# Time Complexity: O(n^2)
# Space Complexity: O(1)
# Topics: Array, Two Pointers, Sorting
# Solution:
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        triplets = []
        lenNums = len(nums)

        nums.sort()   # Sort the List

        for i in range (0, lenNums - 2):  # Iterate through the nums
            if i > 0 and nums[i] == nums[i - 1]:  # Skip the duplicates
                continue

            target = -nums[i]   # Since nums[i] + nums[j] + nums[k] == 0
            left = i + 1
            right = lenNums - 1

            while left < right:
                currSum = nums[left] + nums[right]

                if currSum == target:
                    triplets.append([nums[i], nums[left], nums[right]])

                    left += 1
                    right -= 1

                    while left < right and nums[left] == nums[left - 1]:  # Skip the duplicates
                        left += 1
                    while left < right and nums[right] == nums[right + 1]:  # Skip the duplicates
                        right -= 1

                elif currSum < target:
                    left += 1
                else:
                    right -= 1

        return triplets