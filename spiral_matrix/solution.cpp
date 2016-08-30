#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> ans;
        int num_row = matrix.size();
        int num_col = num_row>0 ? matrix[0].size() : 0;
        int row_start = 0;
        int col_start = 0;
        while(num_row > 0 && num_col > 0) {
            for(int i=0; i<num_col; i++)
                ans.push_back(matrix[row_start][i+col_start]);
            for(int i=1; i<num_row; i++)
                ans.push_back(matrix[i+row_start][col_start+num_col-1]);
            for(int i=num_col-2; i>=0 && num_row > 1; i--)
                ans.push_back(matrix[row_start+num_row-1][col_start+i]);
            for(int i=num_row-2; i>=1 && num_col > 1; i--)
                ans.push_back(matrix[i+row_start][col_start]);
            num_col -= 2;
            num_row -= 2;
            row_start++;
            col_start++;
        }
        return ans; 
    }
};

int main() {
    vector<vector<int> > matrix;
    vector<int> row1;
    row1.push_back(7);
    row1.push_back(9);
    row1.push_back(6);
    vector<int> row2;
    row2.push_back(9);
    vector<int> row3;
    row3.push_back(6);
    matrix.push_back(row1);
    Solution sol;
    vector<int> ans = sol.spiralOrder(matrix);
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << endl;
    }
}
