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
Problem Statement: Count Complete Tree Nodes
Given the root of a complete binary tree, return the number of nodes in the tree.

Example:
Input: root = [1,2,3,4,5,6]
Tree Structure:
     1
    / \
   2   3
  / \  /
 4   5 6

Output: 6
Explanation: There are 6 nodes in the tree.

Constraints:
- The number of nodes in the tree is in the range [0, 5 * 10^4]
- The tree is guaranteed to be complete
- -1000 <= Node.val <= 1000
*/

int countNodes(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int leftCount = countNodes(root->left);
    int rightCount = countNodes(root->right);

    return 1 + leftCount + rightCount;
}

// Driver code - do not modify
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    
    int totalNodes = countNodes(root);
    cout << "Total number of nodes: " << totalNodes << endl;
    
    return 0;
}