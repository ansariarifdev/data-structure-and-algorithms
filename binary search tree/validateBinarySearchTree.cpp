#include <iostream>
#include <limits.h>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
// Implementation of the solve function 
bool solve(TreeNode* root, int minValue, int maxValue) {
    if(root == nullptr) {
        return true;
    }

    return (solve(root->left, minValue, root->val) and solve(root->right, root->val, maxValue))
        and (root->val > minValue and root->val < maxValue);
}
// Function to validate if a binary tree is a valid BST
bool isValidBST(TreeNode* root) {
    // Write your code here
    if(root == nullptr) {
        return true;
    }

    return solve(root, INT_MIN, INT_MAX);
}

int main() {
    // Example: Construct a simple BST
    TreeNode* root = new TreeNode(2);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);

    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    // Clean up memory
    delete root->left;
    delete root->right;
    delete root;

     // Example 1:
    //      2
    //     / \
    //    1   3
    // Expected: true (This is a valid BST)

    // Example 2:
    //      5
    //     / \
    //    1   4
    //       / \
    //      3   6
    // Expected: false (This is NOT a valid BST)
    
    return 0;
}