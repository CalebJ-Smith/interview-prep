# Sudoku Solver
One day I felt like making a sudoku solver; I had recently learned about Branch and Bound algorithms and felt like I would be able to apply it here. So, I wrote one. I found some open source testcases. For testcases that had more than one solution, the testcases I found gave how many solutions there were, while I wrote my code to just give one solution, so that's why there's a diff between mine and the correct.

As a bit of a clarification, I wrote this in late April 2022, but didn't add it to source control until the dates you see listed here.
# Usage
You'll need g++ installed
```bash
make release
time ./sudoku < test.in > test.out.mine
diff test.out.mine test.out.correct
```
