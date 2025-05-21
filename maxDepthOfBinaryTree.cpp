#include <iostream>
#include <algorithm>
using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = DFS(root, 0);
        return res;
    }

    int DFS(TreeNode* root, int count) {
        if (root == nullptr) return count;
        return max(DFS(root->left, count + 1), DFS(root->right, count + 1));
    }
};

// Helper function to build and test the tree
int main() {
    /**
     * Example tree:
     *        1
     *       / \
     *      2   3
     *     /
     *    4
     *
     * Depth = 3
     */

    TreeNode* node4 = new TreeNode(4);
    TreeNode* node2 = new TreeNode(2, node4, nullptr);
    TreeNode* node3 = new TreeNode(3);
    TreeNode* root = new TreeNode(1, node2, node3);

    Solution sol;
    int depth = sol.maxDepth(root);
    cout << "Maximum Depth: " << depth << endl;

    // Clean up memory
    delete node4;
    delete node2;
    delete node3;
    delete root;

    return 0;
}
