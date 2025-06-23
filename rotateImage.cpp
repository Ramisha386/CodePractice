#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose the matrix
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            int k = 0;
            int l = n - 1;
            while (k < l) {
                swap(matrix[i][k], matrix[i][l]);
                k++;
                l--;
            }
        }
    }
};

// Utility function to print the matrix
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Solution sol;
    cout << "Original matrix:" << endl;
    printMatrix(matrix);

    sol.rotate(matrix);

    cout << "\nRotated matrix (90 degrees clockwise):" << endl;
    printMatrix(matrix);

    return 0;
}
