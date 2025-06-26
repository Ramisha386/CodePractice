#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merge;
        sort(intervals.begin(), intervals.end());
        
        int i = 0;
        while (i < intervals.size()) {
            int start = intervals[i][0];
            int end = intervals[i][1];
            int idx = i + 1;

            // Merge overlapping intervals
            while (idx < intervals.size() && end >= intervals[idx][0]) {
                start = min(start, intervals[idx][0]);
                end = max(end, intervals[idx][1]);
                intervals.erase(intervals.begin() + idx); // remove merged interval
                // Do not increment idx; next interval shifts into this position
            }

            merge.push_back({start, end});
            i++;  // move to the next unmerged interval
        }

        return merge;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = sol.merge(intervals);

    cout << "Merged intervals:\n";
    for (const auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
