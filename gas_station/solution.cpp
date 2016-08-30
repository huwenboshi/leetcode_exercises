#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, idx = 0, cur = 0;
        for(int i=0; i<gas.size(); i++) {
            total += gas[i]-cost[i];
            cur += gas[i]-cost[i];
            if(cur < 0) {
                idx = i+1;
                cur = 0;
            }
        }
        if(total < 0) return -1;
        return idx;
    }
};

int main() {
    vector<int> gas;
    vector<int> cost;
    gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(3);
    cost.push_back(2);
    cost.push_back(1);
    cost.push_back(5);
    cost.push_back(1);
    Solution sol;
    cout << sol.canCompleteCircuit(gas, cost) << endl;

}
