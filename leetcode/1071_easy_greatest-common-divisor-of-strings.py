# https://leetcode.com/problems/greatest-common-divisor-of-strings

# For two strings s and t, we say "t divides s" if and only if s = t + ... + t
# (i.e., t is concatenated with itself one or more times).

# Given two strings str1 and str2,
# return the largest string x such that x divides both str1 and str2.


class Solution:
    def all_divisiors(self, s: str) -> set[str]:
        ret = set()
        last_division_len = 0
        for divisions in range(1, len(s) + 1):
            len_division = len(s) // divisions
            if len_division == last_division_len:
                continue
            last_division_len = len_division
            t = s[0:len_division]
            works = True
            for i in range(divisions):
                if t != s[i * len_division : (i + 1) * len_division]:
                    works = False
                    break
            if works:
                ret.add(t)
        return ret

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        all_str1_divisors = self.all_divisiors(str1)
        all_str2_divisors = self.all_divisiors(str2)
        for divisor in sorted(all_str1_divisors, reverse=True):
            if divisor in all_str2_divisors:
                return divisor
        return ""


s = Solution()
sols = {
    ("ABCABC", "ABC"): "ABC",
    ("ABABAB", "ABAB"): "AB",
    ("LEET", "CODE"): "",
    (
        "PWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZ",
        "PWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZPWOLNZ",
    ): "PWOLNZ",
    (
        "AbAbAbAb",
        "AbAbAbAbAb",
    ): "Ab",
}
for (str1, str2), expected in sols.items():
    res = s.gcdOfStrings(str1, str2)
    print("res: ", res, "expected: ", expected, expected == res)

# strings = ["ABCABC", "AAA", "AAAA", "ABAB", "", "A", "AA"]
# for st in strings:
#     res = s.all_divisiors(st)
#     print(st, res)
