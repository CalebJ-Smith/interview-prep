// https://leetcode.com/problems/climbing-stairs/
#include <iostream>
#include <cassert>
using namespace std;

class Solution {
private:
    int arr[45] = {0};
public:
    int climbStairs(int n) {
        assert(1 <= n && n <= 45);
        if(n == 1){
          return 1;
        }
        if(n == 2){
          return 2;
        }
        int stored = arr[n - 1];
        if(stored == 0){
            int answer = climbStairs(n-1) + climbStairs(n-2);
            arr[n - 1] = answer;
            return answer;
        } else{
            cout << "found " << n << ":" << stored << endl;
            return stored;
        }
    }
};