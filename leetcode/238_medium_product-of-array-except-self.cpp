//https://leetcode.com/problems/product-of-array-except-self/
//solved, better than average

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size());
        //Fill answers with the postfix array, then accumulate the prefix value
        answer.back() = 1;
        for(int r_i = answer.size() - 2; r_i >=0; --r_i){
            answer[r_i] = answer[r_i+1] * nums[r_i+1];
        }
        int prefix = 1;
        for(int i = 0; i < answer.size(); ++i){
            answer[i] = answer[i] * prefix;
            prefix *= nums[i];
        }
        return answer;
    }
};