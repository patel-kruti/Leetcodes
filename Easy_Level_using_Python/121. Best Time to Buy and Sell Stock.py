# Problem - 121. Best Time to Buy and Sell Stock
# Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
# Runtime 42 ms Beats 80.26% Analyze Complexity Memory 25.98 MB Beats 78.93%
# Time Complexity: O(n)
# Space Complexity: O(1)
# Solution : 
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        min_price = prices[0]
        best_price = 0
        for i in range(1, len(prices)):
            new_price = prices[i] - min_price
            if best_price < new_price:
                best_price = new_price
            if min_price > prices[i]:
                min_price = prices[i]
        return best_price
