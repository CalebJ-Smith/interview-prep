# https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
# correct, 41percentile speed 12percentile memory


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        maxLen = 1
        currentlyContaining = {s[0]: 0}
        i = 0  # inclusive start of window
        j = 1  # inclusive end of window
        print(s)
        while j < len(s):
            if (
                s[j] in currentlyContaining.keys()
            ):  # cannot extend substring, no longer unique
                newFirstValidIndex = (
                    currentlyContaining[s[j]] + 1
                )  # one after the first occurance of duplicate
                for l in range(i, newFirstValidIndex):
                    currentlyContaining.pop(s[l])
                currentlyContaining[s[j]] = j  # replace
                i = newFirstValidIndex
                maxLen = max(maxLen, len(currentlyContaining))
            else:  # can extend substring
                currentlyContaining[s[j]] = j
                maxLen = max(maxLen, len(currentlyContaining))
            j += 1
        return maxLen
