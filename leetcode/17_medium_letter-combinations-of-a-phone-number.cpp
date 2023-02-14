// https://leetcode.com/problems/letter-combinations-of-a-phone-number
// Correct, about 30th percentile for speed and memory :(
#include <string>
#include <vector>
using namespace std;

class Solution {
 private:
  string numToLetters(char num) {
    switch (num) {
      case '2':
        return "abc";
      case '3':
        return "def";
      case '4':
        return "ghi";
      case '5':
        return "jkl";
      case '6':
        return "mno";
      case '7':
        return "pqrs";
      case '8':
        return "tuv";
      case '9':
        return "wxyz";
      default:
        exit(1);
    }
  }
  vector<string> outputCombos;

  void helper(const string& digits, int digit_i, int option_i, string wip) {
    if (digit_i == digits.size()) {
      return;
    }
    string options = numToLetters(digits[digit_i]);
    if (option_i == options.size()) {
      return;
    }

    wip += options[option_i];
    if (wip.size() == digits.size()) {
      outputCombos.push_back(wip);
      return;
    }

    for (size_t i = 0; i < numToLetters(digits[digit_i + 1]).size(); ++i) {
      helper(digits, digit_i + 1, i, wip);
    }
  }

 public:
  vector<string> letterCombinations(string digits) {
    if (digits.size() == 0) {
      return vector<string>();
    }
    for (size_t i = 0; i < numToLetters(digits[0]).size(); ++i) {
      helper(digits, 0, i, "");
    }
    return outputCombos;
  }
};