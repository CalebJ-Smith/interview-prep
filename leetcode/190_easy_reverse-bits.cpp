//https://leetcode.com/problems/reverse-bits/
//Accepted

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for(uint32_t i = 0; i < 32; ++i){
            uint32_t mask = 1 << i;
            uint32_t bit = mask & n;
            if(bit != 0){// bit has a 1 somewhere in it's bitwise representation
                uint32_t shifted_one = 1 << (31-i);
                res |= shifted_one;
            }
        }
        return res;
    }
};