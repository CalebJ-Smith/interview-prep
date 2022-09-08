// https://leetcode.com/problems/3sum/
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); //n log n
        set<vector<int>> answer_set;
        for(auto i = nums.begin(); i < nums.end() - 2; ++i){ //i's last iter is 3rd last element of array
            if((i + 5) < nums.end() // need space for the middle element and j after we skip two
               && *i == *(i+3))     // only skip if there are four or more of the same element
                continue;
            for(auto j = nums.end()-1; i  < j; --j){ // j is last element of array
                if (j-2 > i && *j == *(j-2)) // Only do the first two elements if there are more than that
                    continue;
                int needed_val = -(*i + *j);
                if (binary_search(i+1, j, needed_val)){ // don't include i or j in the search range
                    answer_set.insert({*i, *j, needed_val});
                }
            }
        }
        
        return vector<vector<int>>(answer_set.begin(), answer_set.end());
    }
};