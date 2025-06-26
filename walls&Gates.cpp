#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Your Solution class
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0) calc(grid,i,j,0);
            }
        }
    }

    void calc(vector<vector<int>>& arr,int i,int j,int cost) {
        int n=arr.size();
        int m=arr[0].size();

        if(i-1>=0 && arr[i-1][j]!=-1 && arr[i-1][j]!=0)
        {
            if(arr[i-1][j]>cost+1)
            {
                 arr[i-1][j]=cost+1;
                 calc(arr,i-1,j,cost+1);
            }
        }
        if(i+1<n && arr[i+1][j]!=-1 && arr[i+1][j]!=0)
        {
            if(arr[i+1][j]>cost+1)
            {
                arr[i+1][j]=cost+1;
                calc(arr,i+1,j,cost+1);
            } 
        }
        if(j-1>=0 && arr[i][j-1]!=-1 && arr[i][j-1]!=0)
        {
            if(arr[i][j-1]>cost+1)
            {
                arr[i][j-1]=cost+1;
                calc(arr,i,j-1,cost+1);
            }
        }
        if(j+1<m && arr[i][j+1]!=-1 && arr[i][j+1]!=0)
        {
            if(arr[i][j+1]>cost+1)
            {
                arr[i][j+1]=cost+1;
                calc(arr,i,j+1,cost+1);
            }
        }
    }
};

int main() {
    const int INF = INT_MAX;

    vector<vector<int>> grid = {
        {INF,  -1,   0,  INF},
        {INF, INF, INF,  -1},
        {INF,  -1, INF,  -1},
        {0,    -1, INF, INF}
    };

    Solution sol;
    sol.islandsAndTreasure(grid);

    // Print the updated grid
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            if (cell == INF)
                cout << "INF ";
            else
                cout << cell << " ";
        }
        cout << endl;
    }

    return 0;
}
