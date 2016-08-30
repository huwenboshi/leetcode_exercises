#include <iostream>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) {
            return 0;
        }
        int *grid = new int[m*n];

        // initialize first row and column
        for(int i=0; i<m; i++) {
            grid[i*n+0] = 1;
        }
        for(int i=0; i<n; i++) {
            grid[0*n+i] = 1;
        }

        // fill the rest
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                grid[i*n+j] = grid[(i-1)*n+j]+grid[i*n+(j-1)];
            }
        }

        // minval
        int num_path = grid[(m-1)*n+(n-1)];
        delete grid;

        return num_path;
    }
};

int main() {
    Solution sol;
    cout << sol.uniquePaths(3,5) << endl;
}
