#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void helper(int m, int n, int k, vector<vector<int> >& result) {
        if(k == 0 || n-m+1 < k)
            return;
        if(k == 1) {
            for(int i=m; i<=n; i++)
                result.push_back(vector<int>(1,i));
            return;
        }
        int result_size = 0;
        for(int i=0; i<n-m+1; i++) {
            helper(m+i+1, n, k-1, result);
            for(int j=result_size; j<result.size(); j++) {
                if(result[j].size() < k)
                    result[j].insert(result[j].begin(),m+i);
            }
            result_size = result.size();
        }
    }
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        helper(1, n, k, result);
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int> > result = sol.combine(4,3);
    for(int i=0; i<result.size(); i++) {
        for(int j=0; j<result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
