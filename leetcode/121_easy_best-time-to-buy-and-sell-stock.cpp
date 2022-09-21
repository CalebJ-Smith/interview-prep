// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
//Accepted. average space & time
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit_so_far = 0, min_price_so_far = __INT_MAX__;
        for(int i = 0; i < prices.size(); ++i){
          if (prices[i] < min_price_so_far){
            min_price_so_far = prices[i];
          }
          int current_profit = (prices[i] - min_price_so_far);
          if(current_profit > max_profit_so_far){
            max_profit_so_far = current_profit;
          }
        }
        return max_profit_so_far;
    }
};