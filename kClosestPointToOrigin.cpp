#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
private:
    priority_queue<pair<int, int>> maxHeap;
    int k;
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        this->k = k;
        for (int i = 0; i < points.size(); ++i) {
            int distSq = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            maxHeap.push({distSq, i});
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;
        while (!maxHeap.empty()) {
            int idx = maxHeap.top().second;
            result.push_back(points[idx]);
            maxHeap.pop();
        }
        return result;
    }
};

int main() {
    vector<vector<int>> points = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int k = 2;

    Solution sol;
    vector<vector<int>> result = sol.kClosest(points, k);

    cout << "The " << k << " closest points to the origin are:\n";
    for (const auto& point : result) {
        cout << "[" << point[0] << ", " << point[1] << "]\n";
    }

    return 0;
}
