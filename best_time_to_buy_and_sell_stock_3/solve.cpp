#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int num_days = prices.size();
        if(num_days == 0) {
            return 0;
        }

        int* max_profit_left = new int[num_days];
        max_profit_left[0] = 0;
        int lowest_price_left = prices[0];
        
        int* max_profit_right = new int[num_days];
        max_profit_right[num_days-1] = 0;
        int highest_price_right = prices[num_days-1];
        
        for(int i=1; i<num_days; i++) {
            int profit_tmp = prices[i]-lowest_price_left;
            if(profit_tmp > max_profit_left[i-1]) {
                max_profit_left[i] = profit_tmp;
            }
            else {
                max_profit_left[i] = max_profit_left[i-1];
            }
            if(prices[i] < lowest_price_left) {
                lowest_price_left = prices[i];
            }

            int j = num_days-1-i;
            profit_tmp = highest_price_right-prices[j];
            if(profit_tmp > max_profit_right[j+1]) {
                max_profit_right[j] = profit_tmp;
            }
            else {
                max_profit_right[j] = max_profit_right[j+1];
            }
            if(prices[j] > highest_price_right) {
                highest_price_right = prices[j];
            }
        }

        int max_profit = 0;

        for(int i=0; i<num_days; i++) {
            int tmp = max_profit_left[i]+max_profit_right[i];
            if(tmp > max_profit) {
                max_profit = tmp;
            }
        }

        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> input;
    input.push_back(1);
    input.push_back(2);
    input.push_back(3);
    input.push_back(1);
    input.push_back(5);
    cout << sol.maxProfit(input) << endl;
}
