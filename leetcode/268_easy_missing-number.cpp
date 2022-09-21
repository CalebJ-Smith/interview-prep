// https://leetcode.com/problems/missing-number/
//Accepted
#include <vector>

using namespace std;


class Solution{
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