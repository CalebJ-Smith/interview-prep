#include <iostream>
#include <set>
using namespace std;
//Given a string s, find the length of the longest substring without repeating characters.
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int maxLength = 0;
        for(size_t i = 0; i < s.length(); i++) {
          set<char> bag;
          int length = 0;
          for(size_t j = i; j < s.length(); j++) {
            if(bag.insert(s[j]).second) length++;
            else break;
          }
          if(length > maxLength) maxLength = length;
        }
        return maxLength;
    }
};


int main(){
  Solution s;
  cout << s.lengthOfLongestSubstring("bbb") << endl;
  cout << s.lengthOfLongestSubstring("andaw") << endl;
}