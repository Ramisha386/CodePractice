#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> arr(n, -1);
        return min(dfs(0, cost, arr), dfs(1, cost, arr));
    }

private:
    int dfs(int i, vector<int>& cost, vector<int>& arr) {
        if (i >= cost.size()) return 0;
        if (arr[i] != -1) return arr[i];
        arr[i] = cost[i] + min(dfs(i + 1, cost, arr), dfs(i + 2, cost, arr));
        return arr[i];
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<int> cost = {10, 15, 20};

    int result = sol.minCostClimbingStairs(cost);
    cout << "Minimum cost to reach the top: " << result << endl;

    return 0;
}
