# https://leetcode.com/problems/spiral-matrix-ii/
# Accepted, but poor memory and time

import sys


class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        def add_tuple(a, b):
            return tuple(map(lambda x: x[0] + x[1], zip(a, b)))

        out = [[0 for _ in range(n)] for _ in range(n)]
        left_inclusive = 0
        right_exclusive = n
        top_inclusive = 0
        bottom_exclusive = n
        dir_vector = (0, 1)
        at = (0, 0)

        for i in range(1, n**2 + 1):
            out[at[0]][at[1]] = i

            # turn corners and mark off boundaries
            would_be_at = add_tuple(at, dir_vector)
            if would_be_at[0] >= bottom_exclusive:
                dir_vector = (0, -1)
                right_exclusive -= 1
            elif would_be_at[0] < top_inclusive:
                dir_vector = (0, 1)
                left_inclusive += 1
            elif would_be_at[1] >= right_exclusive:
                dir_vector = (1, 0)
                top_inclusive += 1
            elif would_be_at[1] < left_inclusive:
                dir_vector = (-1, 0)
                bottom_exclusive -= 1
            at = add_tuple(dir_vector, at)
        return out


if __name__ == "__main__":
    m = Solution()
    print(m.generateMatrix(int(sys.argv[1])))
