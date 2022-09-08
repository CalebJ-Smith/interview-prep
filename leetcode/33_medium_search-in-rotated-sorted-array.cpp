// https://leetcode.com/problems/search-in-rotated-sorted-array/
// I'm getting the wrong answer here
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //Binary search, but do logic with values at begining and end of range. 
        // [first, last]
        int first_i = 0;
        int last_i = nums.size()-1;
        while (first_i <= last_i && first_i >= 0 && last_i < nums.size()){
            size_t midpoint_i = (first_i + last_i) / 2;
            cout << "midpoint_i: " << midpoint_i << " ";
            if (nums[midpoint_i] < target){
                cout << "less-";
                //can tell if range contains pivot or not by comparing nums[first] with nums[last]
                // *the range is between astriks*
                // midpoint_i has _underscores_ around it
                if (nums[first_i] < nums[last_i]){
                    // *4,_5_,6*,7,0,1,2      target = 6    ->
                    // array does not contain pivot. Go to the right
                    cout << "correct ";
                    first_i = midpoint_i + 1;
                }else if (nums[first_i] > nums[last_i]){ 
                    cout << "inverted ";
                    if (nums[last_i] > target){
                        // 4,5,6,*7,_0_,1*,2      target = 7    <-
                        last_i = midpoint_i - 1;
                    }else if (nums[last_i] < target){
                        // 4,5,6,*7,_0_,1*,2      target = 1    ->
                        first_i = midpoint_i + 1;
                    }else{
                        return last_i; // nums[first_i] == target
                    }
                }else{
                    cout << "one_value_return" << endl;
                    return -1; // narrowed down to one value(since it's ascending order with distinct values)
                        // and it's not the target, return -1
                }
            }else if (nums[midpoint_i] > target){
                // 4,*5,_6_,7*,0,1,2 target = 5   <-
                cout << "greater-";
                if (nums[first_i] < nums[last_i]){
                    //correct. go left
                    cout << "correct ";
                    last_i = midpoint_i - 1;
                }else if (nums[first_i] > nums[last_i]){
                    //inverted
                    cout << "inverted ";
                    if (nums[last_i] < target){
                        // 4,5,*6,_7_,0*,1,2 target = 6   <-
                        last_i = midpoint_i - 1;
                    }else if (nums[last_i] > target){
                        // 4,5,*6,_7_,0*,1,2 target = 0   ->  
                        first_i = midpoint_i + 1;
                    }else{
                        return last_i; //nums[last_i] == target
                    }
                }else{ //equal
                     cout << "one_value_return" << endl;
                    return -1; // narrowed down to one value(since it's ascending order with distinct values)
                        // and it's not the target, return -1
                }
            }else{ // nums[midpoint_i] == target
                cout << "equal return" << endl;
                return midpoint_i;
            }
        }
        cout << "default_return" << endl;
        return -1;
        
    }
};