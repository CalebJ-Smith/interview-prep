# https://leetcode.com/problems/letter-combinations-of-a-phone-number
# Correct, about 30th percentile for speed and memory :(
from collections import deque
from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        numToLetter = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }
        possibilities: List[str] = []
        if not digits:
            return possibilities
        currentString = ""
        stack = deque()
        stack.append("")  # indices into phone#, option

        while stack:
            existing = stack.pop()

            existingSize = len(existing)
            if len(existing) == len(digits):
                possibilities.append(existing)
                continue

            options = numToLetter[digits[existingSize]]

            for option in options:
                stack.append(existing + option)

        return possibilities
