#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // solve n queen helper
    void helper(vector<vector<int> > &slns,
            const vector<int> &cur_state, int n) {
        
        // if cur_state has n rows append to solution and return
        if(cur_state.size() == n) {
            slns.push_back(cur_state);
            return;
        }

        // search for possible next moves
        int cur_row = cur_state.size();
        vector<int> next_movs;
        for(int i=0; i<n; i++) {
            bool pass = true;
            for(int j=0; j<cur_state.size(); j++) {
                if(i-cur_state[j] != 0 &&
                   i-cur_state[j] != j-cur_row &&
                   i-cur_state[j] != cur_row-j) {
                    // ok
                }
                else {
                    pass = false;
                    break;
                }
            }
            if(pass) {
                next_movs.push_back(i);
            }
        }

        // explore the next moves
        for(int i=0; i<next_movs.size(); i++) {
            vector<int> next_state(cur_state);
            next_state.push_back(next_movs[i]);
            helper(slns, next_state, n);
        }

        return;
    }

    int totalNQueens(int n) {
        
        // initialize solutions
        vector<vector<int> > slns;

        // start the recursion
        vector<int> cur_state;
        helper(slns, cur_state, n);

        return slns.size();
    }
};

int main() {
    Solution sol;
    cout << sol.totalNQueens(6) << endl;
}
