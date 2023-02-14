# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/
# 50th percentile speed, 16th percentile memory
from types import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        while len(nums) > 2:
            print(nums)
            if nums[0] < nums[-1]:  # Plain array, return first
                return nums[0]

            if nums[0] > nums[len(nums) // 2]:  # rotation in first half
                nums = nums[: 1 + len(nums) // 2]
            else:  # rotation in second half
                nums = nums[1 + len(nums) // 2 :]
        print(nums)
        return min(nums)
