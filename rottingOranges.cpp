#include <iostream>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>> q;

        // Count fresh oranges and push rotten ones
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) fresh++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        if(fresh == 0) return 0; 

        int minutes = -1;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        while(!q.empty()) {
            int sz = q.size();
            minutes++;
            while(sz--) {
                auto [x, y] = q.front(); q.pop();
                for(int d=0; d<4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && grid[nx][ny]==1) {
                        grid[nx][ny] = 2;
                        q.push({nx, ny});
                        fresh--;
                    }
                }
            }
        }

        return (fresh == 0) ? minutes : -1;
    }
};

int main() {
    Solution sol;

    // Example test case
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    cout << sol.orangesRotting(grid) << endl; // Expected output: 4

    return 0;
}
