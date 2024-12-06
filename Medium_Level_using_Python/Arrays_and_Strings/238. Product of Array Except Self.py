# Problem: 238. Product of Array Except Self
# Link: https://leetcode.com/problems/product-of-array-except-self/description/
# Time Complexity: O(n)
# Space Complexity: O(1)
# Topics: Array, Prefix Sum
# Solution:
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        numsLen = len(nums)
        answer = [0] * numsLen
        countZeros = 0
        totalProduct = 1

        for i in range(0, numsLen):
            if nums[i] != 0:
                totalProduct *= nums[i]
            else:
                countZeros += 1

        if countZeros > 1:
            return answer
        elif countZeros == 1:
            for i in range (0, numsLen):
                if nums[i] == 0:
                    answer[i] = totalProduct
        else:
            for i in range (0, numsLen):
                answer[i] = int(totalProduct/nums[i])
        
        return answer