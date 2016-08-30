#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m = obstacleGrid.size();
        if(m == 0) {
            return 0;
        }
        int n = obstacleGrid[0].size();
        if(n == 0) {
            return 0;
        }

        int *grid = new int[m*n];
        for(int i=0; i<m*n; i++) {
            grid[i] = 0;
        }

        if(obstacleGrid[0][0] != 1) {
            grid[0] = 1;
        }

        // initialize first row and column
        for(int i=1; i<m; i++) {
            if(obstacleGrid[i][0] != 1) {
                grid[i*n+0] = grid[(i-1)*n+0];
            }
        }
        for(int i=1; i<n; i++) {
            if(obstacleGrid[0][i] != 1) {
                grid[0*n+i] = grid[0*n+i-1];
            }
        }

        // fill the rest
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(obstacleGrid[i][j] != 1) {
                    grid[i*n+j] = grid[(i-1)*n+j]+grid[i*n+(j-1)];
                }
            }
        }

        // minval
        int num_path = grid[(m-1)*n+(n-1)];
        delete grid;

        return num_path;
    }
};

int main() {
    vector<vector<int> > grid;
    grid.push_back(vector<int>(2,0));
    grid[0][0] = 1;
    Solution sol;
    cout << sol.uniquePathsWithObstacles(grid) << endl;
}
