// https://leetcode.com/problems/top-k-frequent-elements/
//accepted, faster than 60%, less memory than 90%
#include <unordered_map>
#include <queue>
using namespace std;

struct val_cnt{
    int val;
    int count;
};

class val_cnt_comp{
    public:
    bool operator()(const val_cnt& lhs, const val_cnt& rhs){
        return lhs.count < rhs.count;
    }
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(int i : nums) counts[i]++;
        
        priority_queue<val_cnt, vector<val_cnt>, val_cnt_comp> pq;
        for(auto pair: counts){
            pq.push({pair.first, pair.second});
        }
        
        vector<int> out(k);
        for(int i = 0; i < k; i++){
            out[i] = pq.top().val;
            pq.pop();
        }
        return out;
    }
};