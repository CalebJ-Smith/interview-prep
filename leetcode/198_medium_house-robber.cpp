//https://leetcode.com/problems/house-robber/
//Accepted, 99%ile speed and memory
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int total_max = nums[0]; 
        int one_ago_max = nums[0];
        int two_ago_max = 0;
        for(int house = 1; house < nums.size(); ++house){
            int this_max = max(one_ago_max, two_ago_max + nums[house]);
            if(this_max > total_max){
                total_max = this_max;
            }
            two_ago_max = one_ago_max;
            one_ago_max = this_max;
        }
        return total_max;
    }
};