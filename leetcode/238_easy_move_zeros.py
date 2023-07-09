# https://leetcode.com/problems/move-zeroes
from typing import List


class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # front
        read = 0  # lead
        store = 0  # follow
        while read < len(nums):
            if nums[read] == 0:
                read += 1
            else:
                if store != read:
                    nums[store] = nums[read]
                read += 1
                store += 1

        while store < read:
            nums[store] = 0
            store += 1
