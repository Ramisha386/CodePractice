#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if (n == 1) return strs[0];
        string ans;
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            bool flag = true;
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || ch != strs[j][i]) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            ans += ch;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"flower", "flow", "flight"};
    string result = sol.longestCommonPrefix(input);
    cout << "Longest Common Prefix: " << result << endl;
    return 0;
}
