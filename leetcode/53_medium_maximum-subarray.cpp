//https://leetcode.com/problems/maximum-subarray/
// passed


class Solution {
	public:
	int maxSubArray(vector<int>& nums) {
		vector<int> dp(nums.size());
		dp[0] = nums[0];
		int max_v = nums[0];
		for(int i = 1; i < nums.size(); ++i){
			//find the maximum subarray that ENDS at i
			dp[i] = max(dp[i-1] + nums[i], nums[i]);
			if(dp[i] > max_v){
				max_v = dp[i];
			}
		}
		return max_v;        
	}
};
