#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> record;
        for(int i=0; i<s.size(); i++) {
            if(record.empty()) {
                record.push(s[i]);
            }
            else if(record.top() == '(' && s[i] == ')') {
                record.pop();
            }
            else if(record.top() == '[' && s[i] == ']') {
                record.pop();
            }
            else if(record.top() == '{' && s[i] == '}') {
                record.pop();
            }
            else {
                record.push(s[i]);
            }
        }
        return record.empty();
    }
};

int main() {
    Solution sol;
    cout << sol.isValid("()") << endl;
    cout << "-------------------" << endl;
    cout << sol.isValid("([)]") << endl;
}
