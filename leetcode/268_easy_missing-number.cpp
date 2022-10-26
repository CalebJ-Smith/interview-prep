// https://leetcode.com/problems/missing-number/
//Accepted
#include <vector>

using namespace std;


class WorseSolution{
public:
  int missingNumber(vector<int>& nums){
    vector<bool> have_found(nums.size()+1, false);
    for(int& elem : nums){
      have_found[elem] = true;
    }
    //then linear search for the one that's false
    for(int i = 0; i < have_found.size(); ++i){
      if(!have_found[i])
        return i;
    }
    return __INT_MAX__; // this should never happen
  }
};

// A better solution with O(1) extra space
// accepted also
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        //find what the sum of numbers 0 to nums.size() should be
        int sum = (nums.size() * (nums.size() + 1)) / 2;
        // by subtracting all contained numbers, we find the one that is missing
        for(auto it = nums.begin(); it != nums.end(); ++it){
            sum -= *it;
        }
        return sum;
    }
};
