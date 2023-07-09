# https://leetcode.com/problems/merge-strings-alternately
# speed 50th percentile memory 90th percentile
class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        merged = ""
        i = 0
        while i < min(len(word1), len(word2)):
            merged = merged + word1[i] + word2[i]
            i += 1
        merged += word1[i:]
        merged += word2[i:]
        return merged
