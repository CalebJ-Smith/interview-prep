// https://leetcode.com/problems/backspace-string-compare/
#include <iostream>
#include <stack>
#include <string>
using namespace std;
// TO EXECUTE:
//  g++ -std=c++1z -Wconversion -Wall -Werror -Wextra -pedantic 844_medium_backspace-string-compare.cpp -o 844.exe; ./844.exe
// change the test method to use backspaceCompare_stack to get something that works

// O(n) time and O(1) space
// Going to do it in O(n) extra space first cause that's easy with stacks
class Solution {
  stack<char> stackFromString(const string& str) {
    stack<char> _stack;
    for (auto ch : str) {
      if (ch == '#') {
        if (!_stack.empty()) _stack.pop();
      } else {
        _stack.push(ch);
      }
    }
    return _stack;
  }

  bool stackEqual(stack<char>& s_stack, stack<char>& t_stack) {
    if (s_stack.size() != t_stack.size()) return false;
    while (!s_stack.empty() && !t_stack.empty()) {
      if (s_stack.top() != t_stack.top()) return false;
      s_stack.pop();
      t_stack.pop();
    }
    return s_stack.empty() && s_stack.empty();  // if both are empty, then true
  }

 public:
  bool backspaceCompare_stack(string s, string t) {
    stack<char> s_stack = stackFromString(s);
    stack<char> t_stack = stackFromString(t);
    return stackEqual(s_stack, t_stack);
  }

  void moveRIterPastBackspaces(
      std::reverse_iterator<std::string::iterator>& rit,
      const std::reverse_iterator<std::string::iterator>& rend) {
    uint8_t num_backspaces = 0;
    while (*rit == '#' && rit != rend) {
      ++rit;
      ++num_backspaces;
    }
    for (uint8_t num_backspaces_ignored = 0;
         num_backspaces_ignored < num_backspaces && rit != rend;
         ++num_backspaces_ignored) {
      ++rit;
    }
  }

  //O(n) time and O(1) space
  bool backspaceCompare(string s, string t) {
    // iterate through string in reverse, counting number of backspace
    // characters
    auto s_rit = s.rbegin();
    auto t_rit = t.rbegin();
    while (s_rit != s.rend() && t_rit != t.rend()) {
      moveRIterPastBackspaces(s_rit, s.rend());
      moveRIterPastBackspaces(t_rit, t.rend());
      if (s_rit != s.rend() && t_rit != t.rend() 
          && *s_rit != *t_rit) 
        return false;
      s_rit++;
      t_rit++;
    }
    moveRIterPastBackspaces(s_rit, s.rend());
    moveRIterPastBackspaces(t_rit, t.rend());
    return s_rit == s.rend() && t_rit == t.rend(); // if both are empty, then true
  }
};

void test(string s, string t, bool expected) {
  cout << s << " and " << t << " " << flush;
  Solution sol;
  if (sol.backspaceCompare(s, t) == expected) {
    cout << "PASS" << endl;
  } else {
    cout << "FAIL" << endl;
  }
}

// CONSTRAINTS:
// 1 <= s.length, t.length <= 200
// s and t only contain lowercase letters and '#' characters.
int main() {
  test("", "", true);
  test("a", "b", false);
  test("ab#c", "ad#c", true);
  test("a#", "", true);
  test("###", "", true);
  test("###", "a", false);
  test("a#b#", "cd##", true);
  test("a#c", "b", false);
  test("abc#de###", "a", true);
}