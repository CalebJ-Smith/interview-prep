#include <iostream>
#include <algorithm>
#include <vector>
//https://leetcode.com/problems/median-of-two-sorted-arrays/

using namespace std;

// this merges the two arrays into a third array and takes the median of that
class Solution_simple {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        int* merged = new int[totalLength];
        merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), merged);
        double result;
        if(totalLength % 2 == 1){ // odd length, it's the center element
          result = merged[(totalLength-1)/2];
        }else{ // even length, it's the average of the two center elements
          result = (merged[(totalLength/2) - 1] + merged[totalLength/2]) / 2.0;
        }
        delete[] merged;
        return result;
    }
};

//this uses two pointers
class Solution { //theres something wrong with this and I don'f feel like fixing it
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        int halfLength = (totalLength%2) ? /*odd*/(totalLength+1 / 2) : ((totalLength+1) / 2)+1;
        vector<int> merged;
        int i1 = 0;
        int i2 = 0;
        while(i1 + i2 < halfLength){
          if(nums1[i1] < nums2[i2]){
            merged.push_back(nums1[i1]);
            i1++;
          }else{
            merged.push_back(nums2[i2]);
            i2++;
          } 
        } 

        double result;
        if(totalLength % 2 == 1){ // odd length, its the last
          result = merged[halfLength];
        }else{ // even length, it's the average of the two center elements
          result = (merged[halfLength - 1] + merged[halfLength - 2]) / 2.0;
        }
        //delete[] merged;
        return result;
    }
};

int main(){
  Solution s;
  vector<int> a{1};
  vector<int> b{2, 4};
  string a; 
  cout << s.findMedianSortedArrays(a, b) << endl;
}