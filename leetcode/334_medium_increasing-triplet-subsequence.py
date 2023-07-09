# https://leetcode.com/problems/increasing-triplet-subsequence
from typing import List


class Solution:
    def increasingTriplet(self, nums: List[int]) -> bool:
        if len(nums) < 3:
            return False

        lowest = nums[0]
        second_lowest = float("inf")

        for n in nums[1:]:
            if n < lowest:
                #   n, lowest, second_lowest
                lowest = n
                # Don't reset second_lowest. It serves as memory, saying implying that we've seen one lower that that before. Lowest is like a new tracker
            elif n > lowest:
                if n < second_lowest:
                    # lowest, n, second_lowest
                    second_lowest = n
                elif n > second_lowest:
                    # lowest, second_lowest, n
                    return True
        return False
