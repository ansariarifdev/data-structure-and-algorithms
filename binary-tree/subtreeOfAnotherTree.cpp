#include <iostream>
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
Problem Statement: Subtree of Another Tree
Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

Example:
Input: 
root:       subRoot:
     3          4
    / \        / \
   4   5      1   2
  / \
 1   2

Output: true
Explanation: The tree with root 4 in the main tree is identical to the subRoot tree

Constraints:
- The number of nodes in root tree is in the range [1, 2000]
- The number of nodes in subRoot tree is in the range [1, 1000]
- -10^4 <= root.val <= 10^4
- -10^4 <= subRoot.val <= 10^4
*/


// Implementation of the isIdentical function

bool isIdentical(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr or subRoot == nullptr) {
        return root == subRoot;
    }

    bool leftAns = isIdentical(root->left, subRoot->left);
    bool rightAns = isIdentical(root->right, subRoot->right);
    return (leftAns and rightAns) and (root->val == subRoot->val);
}

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(root == nullptr or subRoot == nullptr) {
        return root == subRoot;
    }

    if(root->val == subRoot->val) {
        return isIdentical(root, subRoot);
    } else {
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }



}

// Driver code - do not modify
int main() {
    // Create main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    
    // Create subtree
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    
    bool result = isSubtree(root, subRoot);
    cout << "Is it a subtree? " << (result ? "Yes" : "No") << endl;
    
    return 0;
}