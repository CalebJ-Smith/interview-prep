from typing import List
from math import floor

# https://leetcode.com/problems/can-place-flowers


class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        plantable = 0
        num_in_row = 1
        for flower in flowerbed:
            if flower:
                plantable += max((num_in_row - 1) // 2, 0)
                num_in_row = 0
            else:
                num_in_row += 1
        if flowerbed[-1] == 0:
            num_in_row += 1
            plantable += max(floor((num_in_row - 1) / 2), 0)

        return plantable >= n
