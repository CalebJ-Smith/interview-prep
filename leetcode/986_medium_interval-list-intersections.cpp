// https://leetcode.com/problems/interval-list-intersections/
// This one doesn't work yet
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                           vector<vector<int>>& secondList) {
    vector<vector<int>> toReturn;
    auto firstList_currentPair = firstList.begin();
    auto secondList_currentPair = secondList.begin();
    while(true){
      int start = max((*firstList_currentPair)[0], (*secondList_currentPair)[0]);
      int end;
      if ((*firstList_currentPair)[1] < (*secondList_currentPair)[1]){
        end = (*firstList_currentPair)[1];

      }else if ((*firstList_currentPair)[1] > (*secondList_currentPair)[1]){
        end = (*secondList_currentPair)[1];

      }else{ // equal
        end = (*secondList_currentPair)[1];

      }
    }
    return toReturn;
  }
};
//This will test the function
void test(vector<vector<int>> firstList_in, vector<vector<int>> secondList_in,
          vector<vector<int>> expected) {
  Solution sol;
  if (sol.intervalIntersection(firstList_in, secondList_in) == expected) {
    cout << "PASS" << endl;
  } else {
    cout << "FAIL" << endl;
  }
}

int main() {
  test({{0, 2}, {5, 10}, {13, 23}, {24, 25}},
       {{1, 5}, {8, 12}, {15, 24}, {25, 26}},
       {{1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}});
  test({{1, 3}, {5, 9}}, {}, {});
}