#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/*
Problem Statement: Binary Tree Postorder Traversal
Given the root of a binary tree, return the postorder traversal of its nodes' values.

Example:
Input: root = [1,2,3,4,5]
Tree Structure:
     1
    / \
   2   3
  / \
 4   5

Output: [4,5,2,3,1]

Constraints:
- The number of nodes in the tree is in the range [0, 100]
- -100 <= Node.val <= 100
*/

// Implementation of the solve function 
void solve(TreeNode* root, vector<int> &ans) {
    if(root == nullptr) {
        return ;
    }

    solve(root->left, ans);
    solve(root->right, ans);
    ans.push_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
    if(root == nullptr) {
        return {};
    }

    vector<int> ans;
    solve(root, ans);
    return ans;
}

// Driver code - do not modify
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = postorderTraversal(root);
    
    cout << "Postorder traversal: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}