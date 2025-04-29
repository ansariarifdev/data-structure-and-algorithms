
#include <bits/stdc++.h>
using namespace std;

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
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr or root2 == nullptr) {
            return root1 == root2;
        }

        bool leftAns = isIdentical(root1->left, root2->left);
        bool rightAns = isIdentical(root1->right, root2->right);
        return (leftAns and rightAns) and (root1->val == root2->val);
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create first tree
    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    
    // Create second tree
    TreeNode* root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    
    Solution solution;
    
    cout << "Are trees identical? " << (solution.isIdentical(root1, root2) ? "Yes" : "No") << endl;
    
    solution.deleteTree(root1);
    solution.deleteTree(root2);
    root1 = nullptr;
    root2 = nullptr;
    
    return 0;
}