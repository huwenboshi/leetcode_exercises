#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int min(int a, int b) {
        return a>b ? b : a;
    }
    int minimumTotal(vector<vector<int> > &triangle) {
        vector<int> cur_min_path_sum;
        for(int i=0; i<triangle.size(); i++) {
            vector<int> next_min_path_sum;
            if(cur_min_path_sum.size() == 0) {
                next_min_path_sum.push_back(triangle[0][0]);
            }
            else {
                int first = cur_min_path_sum[0]+triangle[i][0];
                next_min_path_sum.push_back(first);
                for(int j=1; j<i; j++) {
                    int val1 = cur_min_path_sum[j-1]+triangle[i][j];
                    int val2 = cur_min_path_sum[j]+triangle[i][j];
                    next_min_path_sum.push_back(min(val1, val2));
                }
                int last = cur_min_path_sum[i-1]+triangle[i][i];
                next_min_path_sum.push_back(last);
            }
            cur_min_path_sum = next_min_path_sum;
        }
        int min_val = cur_min_path_sum[0];
        for(int i=1; i<cur_min_path_sum.size(); i++) {
            if(cur_min_path_sum[i] < min_val) {
                min_val = cur_min_path_sum[i];
            }
        }
        return min_val;
    }
};

int main() {
    vector<vector<int> > triangle;
    
    vector<int> row1;
    row1.push_back(2);
    
    vector<int> row2;
    row2.push_back(3);
    row2.push_back(4);

    vector<int> row3;
    row3.push_back(6);
    row3.push_back(5);
    row3.push_back(7);

    vector<int> row4;
    row4.push_back(4);
    row4.push_back(1);
    row4.push_back(8);
    row4.push_back(3);

    triangle.push_back(row1);
    triangle.push_back(row2);
    triangle.push_back(row3);
    triangle.push_back(row4);

    for(int i=0; i<triangle.size(); i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }

    Solution sol;
    cout << sol.minimumTotal(triangle) << endl;
}
