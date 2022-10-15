//https://leetcode.com/problems/group-anagrams/submissions/
// Accepted, 70% ish percentile
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        //sort each string then store the map
        for(int i = 0; i < strs.size(); ++i){
            string sorted = strs[i];
            sort(sorted.begin(), sorted.end());
            m[sorted].push_back(strs[i]);
        }
        vector<vector<string>> out;
        for(auto it = m.begin(); it != m.end(); ++it){
            out.push_back(it->second);
        }
        return out;
    }
};