
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

    bool checkIdentical(TreeNode* firstRoot, TreeNode* secondRoot) {
        if(firstRoot == nullptr or secondRoot == nullptr) {
            return firstRoot == secondRoot;
        }

        return (checkIdentical(firstRoot->left, secondRoot->right) 
            and checkIdentical(firstRoot->right, secondRoot->left))
            and firstRoot->val == secondRoot->val;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr) {
            return false;
        } else if(root->left == nullptr and root->right == nullptr) {
            return true;
        } else {
            return checkIdentical(root->left, root->right);
        }
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create a symmetric tree for testing
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    
    Solution solution;
    
    cout << "Is tree symmetric? " << (solution.isSymmetric(root) ? "Yes" : "No") << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}