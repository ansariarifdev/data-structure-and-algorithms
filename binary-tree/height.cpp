#include <iostream>
#include <algorithm>
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
Problem Statement: Maximum Depth/Height of Binary Tree
Given the root of a binary tree, return its maximum depth/height.
The maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node.

Example:
Input: root = [1,2,3,4,5]
Tree Structure:
     1
    / \
   2   3
  / \
 4   5

Output: 3
Explanation: The maximum depth is 3 (path: 1->2->4 or 1->2->5)

Constraints:
- The number of nodes in the tree is in the range [0, 10^4]
- -100 <= Node.val <= 100
*/

int maxDepth(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);

    return max(leftHeight, rightHeight) + 1;
}

// Driver code - do not modify
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    int height = maxDepth(root);
    cout << "Height of the binary tree: " << height << endl;
    
    return 0;
}