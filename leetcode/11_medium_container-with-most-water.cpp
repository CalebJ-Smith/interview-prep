//https://leetcode.com/problems/container-with-most-water
//Accepted
//Two pointer approach
#include <vector>
#include <algorithm>
using namespace std;



class Solution {
  int area(int i_1, int height_1, int i_2, int height_2){
    return (i_2-i_1) * min(height_1, height_2); 
  }
public:
    int maxArea(vector<int>& height) {
        int i_1 = 0, i_2 = height.size() - 1;
        int max_so_far = 0;
        while(i_1 < i_2){
          int this_area = area(i_1, height[i_1], i_2, height[i_2]);
          max_so_far = max(max_so_far, this_area);
          //move the shorter pillar
          if(height[i_1] < height[i_2]){
            i_1++;
          }else{
            i_2--;
          }
        }
        return max_so_far;
    }
};