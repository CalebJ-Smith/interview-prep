//https://leetcode.com/problems/longest-palindromic-substring/
// This one doesn't work
#include<string>
#include<iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int max = 0;
        int max_begin = 0;
        for(int parity = 0; parity < 2; parity++){
            cout << "swapping parity to " << parity << endl;
            for(int center = 0; center < (int)s.length(); center++){
                int out_back = parity; // start at 0 and 1 to compare even and odd length palindromes
                int out_front = 1;
                while(center - out_back >= 0 && center + out_front < (int)s.length()){
                    cout << "center-out_back " << center-out_back << " center+out_front " << center+out_front << endl;
                    if(s[center-out_back] != s[center+out_front]) {
                        cout << "Breaking, we're looking at " << s.substr(center-out_back, out_front-out_back) << endl;
                        break;
                    } else if(center - out_back-1 >= 0 && center + out_front+1 < (int)s.length()){
                        out_back++;
                        out_front++;
                    } else break;
                }
                if(out_front + out_back +1 > max){
                    cout << "   center:" << center << " center-out_back " << center-out_back << " center+out_front " << center+out_front << endl;
                    max = out_front + out_back +1;
                    max_begin = center - out_back;
                    cout << "  max :  "<< s.substr(max_begin, max) << endl;
                }
            }
        }
        cout << "substr args: " << max_begin << " " << max << endl;
        string asd = s.substr(max_begin, max);
        return asd;
    }
};

int main(){
  Solution s;
  cout << s.longestPalindrome("abba") << endl;
  cout << s.longestPalindrome("babad") << endl;
  cout << s.longestPalindrome("cadac") << endl;
}