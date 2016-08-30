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

        int max_profit = 0;
        int lowest_price = prices[0];

        for(int i=1; i<num_days; i++) {

            int profit_tmp = prices[i]-lowest_price;
            if(profit_tmp > max_profit) {
                max_profit = profit_tmp;
            }

            if(prices[i] < lowest_price) {
                lowest_price = prices[i];
            }
        }

        return max_profit;
    }
};

int main() {
    Solution sol;
    vector<int> input;
    input.push_back(5);
    input.push_back(4);
    input.push_back(2);
    input.push_back(1);
    input.push_back(4);
    cout << sol.maxProfit(input) << endl;
}
