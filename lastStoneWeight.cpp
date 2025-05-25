#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
private:
    priority_queue<int> maxHeap;

public:
    int lastStoneWeight(vector<int>& stones) {
        for (int num : stones) {
            maxHeap.push(num);
        }
        return calculate();
    }

    int calculate() {
        while (maxHeap.size() > 1) {
            int y = maxHeap.top();
            maxHeap.pop();
            int x = maxHeap.top();
            maxHeap.pop();
            if (x != y) {
                maxHeap.push(y - x);
            }
        }
        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};

int main() {
    Solution solution;
    vector<int> stones = {2, 7, 4, 1, 8, 1}; // Example input

    int result = solution.lastStoneWeight(stones);
    cout << "Last stone weight: " << result << endl;

    return 0;
}
