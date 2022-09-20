// https://leetcode.com/problems/valid-parentheses/
// Accepted
#include <string>
#include <stack>
using namespace std;


class Solution {
  bool closingIsValid(stack<char>& stax, char in){
    if(stax.empty() || stax.top() != in)
      return false;
    stax.pop();
    return true;    
  }
public:
    bool isValid(string s) {
      stack<char> stax;
      for(auto it = s.begin(); it != s.end(); it++){
        switch (*it){
          case '(': 
          case '{':
          case '[':
            stax.push(*it);
            break;
          case ')':
            if(!closingIsValid(stax, '('))
              return false;
            break;
          case '}':
            if(!closingIsValid(stax, '{'))
              return false;
            break;
          case ']':
            if(!closingIsValid(stax, '['))
              return false;
            break;
          default: 
            return false;
        }
      }  
      return stax.empty();      
    }
};