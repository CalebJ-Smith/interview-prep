//https://leetcode.com/problems/maximum-subarray/
// passed, 90% memory 80% performance 


class Solution {
	public:
	int maxSubArray(vector<int>& nums) {
		int last = nums[0];
		int max_v = nums[0];
		for(int i = 1; i < nums.size(); ++i){
			//find the maximum subarray that ENDS at i
			last = max(last + nums[i], nums[i]);
			if(last > max_v){
				max_v = last;
			}
		}
		return max_v;        
	}
};
