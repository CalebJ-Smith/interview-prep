// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>;
#include <vector>;

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())
            return {-1, -1};
        size_t first_i = 0;
        int last_i = nums.size()-1;
        size_t found_target_at_i = -1;
        while (true){
            size_t midpoint_i = (last_i + first_i) / 2;
            if (nums[midpoint_i] < target) {
                first_i = midpoint_i;
            } else if (target < nums[midpoint_i]){
                last_i = midpoint_i;
            }else{ // found target
                found_target_at_i = midpoint_i;
                break;
            }
            if (first_i + 1 == last_i){
                return {-1, -1};
            }
        }
        cout << "found target at " << found_target_at_i << endl;
        //if (found_target_at_i == -1) //target isn't in array
        //    return {-1, -1};

        // now we have a range where the target could be [first_i, last_i]; just need to narrow it down
        //binary search for begining of range
        size_t finding_firsts_last_i = found_target_at_i;
        while(first_i < finding_firsts_last_i){
            size_t finding_firsts_midpoint_i = (finding_firsts_last_i + first_i) / 2;
            if(nums[finding_firsts_midpoint_i] < target){
                first_i = finding_firsts_midpoint_i + 1;
            }else{
                finding_firsts_last_i = finding_firsts_midpoint_i - 1;
            }
        }
        cout << "first_i " << first_i << endl;
        
        //binary search for end of range
        size_t finding_lasts_first_i = found_target_at_i;
        while(finding_lasts_first_i + 1 < last_i){
            size_t finding_lasts_midpoint_i = (finding_lasts_first_i + last_i) / 2;
            if(nums[finding_lasts_midpoint_i] <= target){
                finding_lasts_first_i = finding_lasts_midpoint_i - 1;
            }else{
                last_i = finding_lasts_midpoint_i + 1;
            }
        }
        int first = first_i;// + 1;
        int last = last_i;// -1;
        return {first, last};
    }
};

int main(){
  Solution s; 
  cout << s.searchRange(vector<int>{1}, 1) << endl;
}