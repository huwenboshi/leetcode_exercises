#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > matrix;
        for(int i=0; i<n; i++) {
            vector<int> tmp(n, 0);
            matrix.push_back(tmp);
        }
        int num_row = matrix.size();
        int num_col = num_row>0 ? matrix[0].size() : 0;
        int row_start = 0;
        int col_start = 0;
        int val = 1;
        while(num_row > 0 && num_col > 0) {
            for(int i=0; i<num_col; i++, val++)
                matrix[row_start][i+col_start] = val;
            for(int i=1; i<num_row; i++, val++)
                matrix[i+row_start][col_start+num_col-1] = val;
            for(int i=num_col-2; i>=0 && num_row > 1; i--, val++)
                matrix[row_start+num_row-1][col_start+i] = val;
            for(int i=num_row-2; i>=1 && num_col > 1; i--, val++)
                matrix[i+row_start][col_start] = val;
            num_col -= 2;
            num_row -= 2;
            row_start++;
            col_start++;
        }
        return matrix; 
    }
};

int main() {
    Solution sol;
    vector<vector<int> > ans = sol.generateMatrix(3);
    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
}
