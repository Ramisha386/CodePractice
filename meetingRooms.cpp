#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Definition of Interval:
 */
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });
        int n = intervals.size();
        for (int i = 0; i < n - 1; i++) {
            if (intervals[i].end > intervals[i + 1].start) return false;
        }
        return true;
    }
};

int main() {
    // Create a vector of intervals
    vector<Interval> intervals = {
        Interval(0, 30),
        Interval(5, 10),
        Interval(15, 20)
    };

    Solution sol;
    bool result = sol.canAttendMeetings(intervals);

    cout << (result ? "Yes, can attend all meetings" : "No, cannot attend all meetings") << endl;

    return 0;
}
