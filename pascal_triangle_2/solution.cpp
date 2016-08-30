#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> last_row;
        vector<int> row;

        rowIndex = rowIndex+1;
        if(rowIndex > 0) {
            last_row.push_back(1);
            row = last_row;
        }

        for(int i=1; i<rowIndex; i++) {
            row.clear();
            row.push_back(1);
            for(int j=0; j<last_row.size()-1; j++) {
                row.push_back(last_row[j]+last_row[j+1]);
            }
            row.push_back(1);
            last_row = row;
        }

        return row;
    }
};

int main() {
    Solution sol;
    vector<int> row = sol.getRow(4);
    for(int i=0; i<row.size(); i++) {
        cout << row[i] << " ";
    }
    cout << endl;
}
