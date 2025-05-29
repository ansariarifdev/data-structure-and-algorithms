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
Problem Statement: Sum of Nodes in Binary Tree
Given the root of a binary tree, return the sum of all nodes in the tree.

Example:
Input: root = [1,2,3,4,5]
Tree Structure:
     1
    / \
   2   3
  / \
 4   5

Output: 15
Explanation: 1 + 2 + 3 + 4 + 5 = 15

Constraints:
- The number of nodes in the tree is in the range [0, 1000]
- -1000 <= Node.val <= 1000
*/

int sumOfNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return root->val + leftSum + rightSum;
}

// Driver code - do not modify
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int sum = sumOfNodes(root);
    cout << "Sum of all nodes: " << sum << endl;
    
    return 0;
}