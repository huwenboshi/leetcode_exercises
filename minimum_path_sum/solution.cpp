#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a>b ? b : a;
    }
    int minPathSum(vector<vector<int> > &grid) {
        int nrow = grid.size();
        int ncol = grid[0].size();

        vector<vector<int> >cost;
        for(int i=0; i<nrow; i++) {
            cost.push_back(vector<int>(ncol,0));
        }

        // fill first row and column
        cost[0][0] = grid[0][0];
        for(int j=1; j<ncol; j++) {
            cost[0][j] = grid[0][j]+cost[0][j-1];
        }
        for(int i=1; i<nrow; i++) {
            cost[i][0] = grid[i][0]+cost[i-1][0];
        }
       
        // fill the rest
        for(int i=1; i<nrow; i++) {
            for(int j=1; j<ncol; j++) {
                cost[i][j] = min(cost[i-1][j],cost[i][j-1])+grid[i][j];
            }
        }

        return cost[nrow-1][ncol-1];        
    }
};

int main() {
    vector<vector<int> > grid;
    for(int i=0; i<3; i++) {
        grid.push_back(vector<int>(4));
    }
    grid[0][0] = 1; grid[0][1] = 2; grid[0][2] = 7; grid[0][3] = 0;
    grid[1][0] = 5; grid[1][1] = 1; grid[1][2] = 8; grid[1][3] = 2;
    grid[2][0] = 4; grid[2][1] = 7; grid[2][2] = 2; grid[2][3] = 1;
    Solution sol;
    cout << sol.minPathSum(grid) << endl;
}
