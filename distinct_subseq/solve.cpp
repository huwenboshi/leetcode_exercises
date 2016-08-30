#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int nums = s.size();
        int numt = t.size();

        if(nums < numt) {
            return 0;
        }

        int* num_sub = new int[2*(nums+1)];
        int* num_sub_next = &num_sub[nums+1];
        for(int j=0; j<nums+1; j++) {
            num_sub[j] = 1;
        }
        
        for(int i=0; i<numt; i++) {
            num_sub_next[i] = 0;
            for(int j=i; j<nums; j++) {
                num_sub_next[j+1] = num_sub_next[j];
                if(t[i] == s[j]) {
                    num_sub_next[j+1] += num_sub[j];
                }
            }
            int* tmp = num_sub;
            num_sub = num_sub_next;
            num_sub_next = tmp;
        }
        return num_sub[nums];
    }
};

int main() {
    Solution sol;
    string s = "ABBCCE";
    string t = "BCE";
    cout << sol.numDistinct(s,t) << endl;
}
