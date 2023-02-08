//https://leetcode.com/problems/string-to-integer-atoi/description/
// beats 100% on runtime, 62% on memory
class Solution {
public:
    int myAtoi(string s) {
        signed long answer = 0;
        int i = 0;
        bool is_positive = true;
        int pos_max = INT_MAX / 10;
        int neg_min = INT_MIN / 10;

        for(; s[i] == ' ' && i < s.size(); ++i);

        if(s[i] == '-'){
            is_positive = false;
            ++i;
        }else if (s[i] == '+'){
            ++i;
        }

        for(; i < s.size(); ++i){
            char current = s[i];
            if(current < '0' || current > '9'){
                break;
            }
            int val = (int)current - 48;
            if(!is_positive){
                val = -val;
            }
            if(answer > pos_max){
                answer = INT_MAX;
            }else if (answer < neg_min ){
                answer = INT_MIN;
            }else{
                answer *= 10;
                answer += val;
            }
        }
        if(answer > INT_MAX ){
            answer = INT_MAX;
        }else if (answer < INT_MIN ){
            answer = INT_MIN;
        }

        return (int)answer;
    }
};
