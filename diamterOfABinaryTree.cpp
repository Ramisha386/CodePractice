#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxd = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        int leftHeight, rightHeight;
        if (root->left != nullptr) leftHeight = dfs(root->left);
        else leftHeight = 0;
        if (root->right != nullptr) rightHeight = dfs(root->right);
        else rightHeight = 0;
        if (rightHeight + leftHeight > maxd) return rightHeight + leftHeight;
        else return maxd;
    }

    int dfs(TreeNode* root) {
        int diameter, rightHeight, leftHeight;
        if (root->left == nullptr && root->right == nullptr) {
            diameter = 0;
            return 1;
        } else {
            if (root->left != nullptr) leftHeight = dfs(root->left);
            else leftHeight = 0;
            if (root->right != nullptr) rightHeight = dfs(root->right);
            else rightHeight = 0;
            diameter = rightHeight + leftHeight;
            if (maxd < diameter) maxd = diameter;
            return max(leftHeight + 1, rightHeight + 1);
        }
    }
};

// Helper function to build tree from level-order list (use -1 as null)
TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < nodes.size()) {
        TreeNode* curr = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != -1) {
            curr->left = new TreeNode(nodes[i]);
            q.push(curr->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != -1) {
            curr->right = new TreeNode(nodes[i]);
            q.push(curr->right);
        }
        i++;
    }

    return root;
}

int main() {
    // Construct tree: root = [1, null, 2, 3, 4, null, 5, null, 6]
    vector<int> nodes = {1, -1, 2, 3, 4, -1, 5, -1, 6};

    TreeNode* root = buildTree(nodes);

    Solution sol;
    int result = sol.diameterOfBinaryTree(root);
    cout << "Diameter of the binary tree: " << result << endl;

    return 0;
}
