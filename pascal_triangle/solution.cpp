#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > triangle;
        if(numRows >= 1) {
            vector<int> row;
            row.push_back(1);
            triangle.push_back(row);
        }
        for(int i=1; i<numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for(int j=0; j<triangle[i-1].size()-1; j++) {
                row.push_back(triangle[i-1][j]+triangle[i-1][j+1]);
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > triangle = sol.generate(0);
    for(int i=0; i<triangle.size(); i++) {
        for(int j=0; j<triangle[i].size(); j++) {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }
}
