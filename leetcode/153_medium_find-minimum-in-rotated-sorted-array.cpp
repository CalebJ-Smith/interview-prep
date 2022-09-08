// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (l < r){
            int mid = (l + r) / 2;
            if (nums[l] < nums[r]){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return nums[l];
    }
};