// https://leetcode.com/problems/search-a-2d-matrix/

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (target < matrix[0][0] )
            return false;
        vector<int> index;
        for(size_t r = 0; r < matrix.size(); ++r){
            index.push_back(matrix[r][0]);
        }
        // upper bound return first element which is >value. If not, return end().
        // lower bound return first element which is ≥value. If not, return end().
        auto r_iter_to_look = upper_bound(index.begin(), index.end(), target); 
        r_iter_to_look--; //get the element that is <= target
        int r_to_look = distance(index.begin(), r_iter_to_look);
        return binary_search(matrix[r_to_look].begin(), matrix[r_to_look].end(), target);
    }
};