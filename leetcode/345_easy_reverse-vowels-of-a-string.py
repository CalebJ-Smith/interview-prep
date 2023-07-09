# https://leetcode.com/problems/reverse-vowels-of-a-string


class Solution:
    def reverseVowels(self, s: str) -> str:
        vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}
        stack = []
        for letter in s:
            if letter in vowels:
                stack.append(letter)
        out = list(s)
        for i, letter in enumerate(s):
            if letter in vowels:
                out[i] = stack.pop()
        return "".join(out)
