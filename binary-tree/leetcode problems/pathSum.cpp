
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) {
            return false;
        }
        if(root->left == nullptr and root->right == nullptr) {
            return targetSum == root->val;
        }

        return hasPathSum(root->left, targetSum - root->val) or 
            hasPathSum(root->right, targetSum - root->val);

        targetSum += root->val;
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create test tree
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);
    
    Solution solution;
    int targetSum = 22;  // Path sum to find (5->4->11->2 = 22)
    
    cout << "Has path sum " << targetSum << "? " 
         << (solution.hasPathSum(root, targetSum) ? "Yes" : "No") << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}