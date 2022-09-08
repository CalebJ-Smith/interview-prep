//https://leetcode.com/problems/zigzag-conversion/
// this one doesn't work
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string* stuff = new string[numRows];
        int s_i = 0;
        int rowNum = 0;
        bool countingUp = true;
        while(s_i < (int)s.length()){
            stuff[rowNum].push_back(s[s_i]);
            if(countingUp) rowNum++;
            else rowNum--;
            if(rowNum >= numRows) countingUp = false;
            if(rowNum <= 0) countingUp = true;
        }
        
        string toReturn;
        for(int row = 0; row < numRows; row++){
            toReturn += stuff[row];
        }
        
        
        delete stuff;
        return toReturn;
    }
};

int main(){
    Solution s; 
    cout << s.convert("A", 1) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
}