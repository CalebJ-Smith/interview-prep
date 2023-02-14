# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
from types import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        bestProfit = 0
        lowestPrice = prices[0]
        for i in range(len(prices)):
            lowestPrice = min(lowestPrice, prices[i])
            bestProfit = max(bestProfit, prices[i] - lowestPrice)
        return bestProfit
