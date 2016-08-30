#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int end, start;
        for(end=s.size()-1; end>=0 && s[end]==' '; end--);
        for(start=end; start>=0 && s[start]!=' '; start--);
        return end-start;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLastWord("Hello World") << endl;
}
