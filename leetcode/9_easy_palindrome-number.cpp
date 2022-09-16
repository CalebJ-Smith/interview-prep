// https://leetcode.com/problems/palindrome-number/

#include <cmath>
#include <iostream>
#include <string>
using namespace std;

//A naive solution using std::to_string
class Solution_to_string {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {  // "-121" != "121-"
      return false;
    }
    string s = to_string(x);
    int l = 0, r = s.length() -1;
    while(l < r){
      if (s[l] != s[r])
        return false;
      l++;
      r--;
    }
    return true;
  }
};

// a solutino using math
class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) {  // "-121" != "121-"
      return false;
    }
    long left_place_value = pow(10, 9);  // place value of 2^32-1
    long one_left_of_right_place_value = 10;
    // find highest place value of
    for (; left_place_value > x; left_place_value /= 10)
      ;
    while (left_place_value >= one_left_of_right_place_value) {
      int left = ((x % (10 * left_place_value)) - (x % left_place_value)) /
                 left_place_value;
      int right = ((x % one_left_of_right_place_value) -
                   (x % (one_left_of_right_place_value / 10))) /
                  (one_left_of_right_place_value / 10);
      // cout << "left_place_value: " << left_place_value << " moded: " << left
      //      << " one_left_of_right: " << one_left_of_right_place_value
      //      << " modded: " << right << endl;
      if (left != right) {
        return false;
      }
      left_place_value /= 10;
      one_left_of_right_place_value *= 10;
    }
    return true;
  }
};

void test(Solution s, int x) {
  cout << x << ": " << flush;
  cout << s.isPalindrome(x) << endl;
}

int main() {
  Solution s;
  test(s, -121);
  test(s, 121);
  test(s, 10);
  test(s, 100);
  test(s, 1001);
  test(s, 1234567899);
}