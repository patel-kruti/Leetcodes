// Problem - 121. Best Time to Buy and Sell Stock
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Runtime 0ms Beats 100.00% Analyze Complexity Memory 96.00 MB Beats 98.69%
// Solution : 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;

        for(int i = 1; i < prices.size(); i++){
            if(prices[i] < minPrice){
                minPrice = prices[i];
            } else if(prices[i] - minPrice > maxProfit){
                maxProfit = prices[i] - minPrice;
            }
        }
        return maxProfit;
    }
};