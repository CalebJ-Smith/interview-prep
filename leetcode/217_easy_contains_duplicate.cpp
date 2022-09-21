// https://leetcode.com/problems/contains-duplicate/
// Accepted.
#include <set>
#include <vector>
using namespace std;

//This one was easy, but ran a bit slow
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> a(nums.begin(), nums.end());
        return a.size() != nums.size();
    }
};
// This one I tried to cut out operations that weren't necesary via early return
// It did moderatly better. 
class Solution{
  public:
    bool containsDuplicate(vector<int>& nums){
      set<int> a;
      int previous_size = 0;
      for(const auto &elem : nums){
        a.insert(elem);
        if(a.size() != ++previous_size)
          return true;
      }
      return false;
    }
};