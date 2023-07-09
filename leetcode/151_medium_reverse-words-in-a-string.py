# https://leetcode.com/problems/reverse-words-in-a-string


class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.strip().split(" ")
        ws = []
        for w in words:
            if w.strip() != "":
                ws.append(w.strip())
        ws.reverse()
        return " ".join(ws)
