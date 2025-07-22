#include <iostream>
using namespace std;

// Definition for a binary tree node.
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr && q==nullptr) return true;
        bool flagleft=true;
        bool flagright=true;
        if(p!=nullptr && q==nullptr) return false;
        if(p==nullptr && q!=nullptr) return false;
        if(p->val!=q->val) return false;
        if(p->left!=nullptr && q->left==nullptr) return false;
        if(p->left==nullptr && q->left!=nullptr) return false;
        if(p->right!=nullptr && q->right==nullptr) return false;
        if(p->right==nullptr && q->right!=nullptr) return false;
        if(p->left!=nullptr && q->left!=nullptr) flagleft=check(p->left,q->left);
        if(p->right!=nullptr && q->right!=nullptr) flagright=check(p->right,q->right);
        return flagleft && flagright;
    }

    bool check(TreeNode* p, TreeNode* q) {
        bool flagleft=true;
        bool flagright=true;
        if(p!=nullptr && q==nullptr) return false;
        if(p==nullptr && q!=nullptr) return false;
        if(p->val!=q->val) return false;
        if(p->left!=nullptr && q->left==nullptr) return false;
        if(p->left==nullptr && q->left!=nullptr) return false;
        if(p->right!=nullptr && q->right==nullptr) return false;
        if(p->right==nullptr && q->right!=nullptr) return false;
        if(p->left!=nullptr && q->left!=nullptr) flagleft=check(p->left,q->left);
        if(p->right!=nullptr && q->right!=nullptr) flagright=check(p->right,q->right);
        return flagleft && flagright;
    }
};

int main() {
    // Create Tree 1
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    // Create Tree 2 (same structure and values as Tree 1)
    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    Solution solution;
    bool result = solution.isSameTree(tree1, tree2);

    if(result) {
        cout << "The trees are the same." << endl;
    } else {
        cout << "The trees are different." << endl;
    }

    // Clean up memory
    delete tree1->left;
    delete tree1->right;
    delete tree1;

    delete tree2->left;
    delete tree2->right;
    delete tree2;

    return 0;
}
