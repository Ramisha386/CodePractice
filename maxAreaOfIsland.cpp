#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for std::max
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int row = grid.size();
        int col = grid[0].size();
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        int maxArea = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int area = bfs(grid, visited, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }

private:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int row = grid.size();
        int col = grid[0].size();
        int area = 0;
        queue<pair<int, int>> q;
        q.push({i, j});
        visited[i][j] = true;

        vector<pair<int, int>> directions = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            area++;

            for (auto [dx, dy] : directions) {
                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < row && ny >= 0 && ny < col &&
                    grid[nx][ny] == 1 && !visited[nx][ny]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
        return area;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Solution sol;
    int result = sol.maxAreaOfIsland(grid);
    cout << "Maximum area of island: " << result << endl; // Expected output: 6

    return 0;
}
