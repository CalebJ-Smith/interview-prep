#include <iostream>
#include <set>
using namespace std;
//Given a string s, find the length of the longest substring without repeating characters.
//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//accepted
//99% speed, 91% memory

//kinda sliding window, kinda two pointer. O(n)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cache[256]; //a char has a max value between 0 and 255
        for(int i = 0; i < 256; ++i)
            cache[i] = -1;
        int max_v = 0;
        //sliding window
        for(int fast = 0, slow = 0; fast < s.size(); ++fast){
            if(cache[s[fast]] >= slow){
                // the character at s[fast] has appeared after the slow pointer. 
                //[fast, slow] is not a valid window
                slow = cache[s[fast]] + 1;
            }
            int current_size = fast - slow + 1;
            if(current_size > max_v){
                max_v = current_size;
            }
            cache[s[fast]] = fast;
        }
        return max_v;
    }
};

//slower, original, more intuitive solution
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