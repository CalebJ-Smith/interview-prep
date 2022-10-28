// https://leetcode.com/problems/two-sum/
// works, could do it faster now
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0; i < nums.size() -1; i++){
            for(int j = i + 1; j < nums.size(); j++){
                if(nums[i] + nums[j] == target) return vector<int>{i,j};
            }
        }
        return vector<int>();
    }
};

// This is a O(n) solution that is median speed, better than 13% memory

class Solution {
	public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> val2idx;
		for(size_t i = 0; i < nums.size(); ++i){ //O(n)
			val2idx[nums[i]] = i;
		}
			            
		for(int i = 0; i < nums.size(); ++i){
			int desired = target - nums[i];
			auto found = val2idx.find(desired);
			if(found != val2idx.end() && found->second != i){
				return {i, found->second};
			}
		}
		//guarenteed to never get here by problem statement
		return {0,0};
	}
}
