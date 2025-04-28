#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();
        if (numRows == 1 || n <= numRows) return s;

        vector<string> rows(min(numRows, n));
        int currentRow = 0;
        bool goingDown = false;

        for (int i = 0; i < n; ++i) {
            rows[currentRow] += s[i];
            // Change direction when we reach top or bottom row
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }
            // Move up or down
            currentRow += goingDown ? 1 : -1;
        }

        string finalString;
        for (const string& row : rows) {
            finalString += row;
        }

        return finalString;
    }
};

int main() {
    Solution sol;
    string s;
    int numRows;
    
    cout << "Enter the string: ";
    cin >> s;
    
    cout << "Enter number of rows: ";
    cin >> numRows;
    
    string result = sol.convert(s, numRows);
    
    cout << "Zigzag Conversion: " << result << endl;
    
    return 0;
}
