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
Problem Statement: Same/Identical Tree
Given the roots of two binary trees p and q, check if they are identical.
Two binary trees are identical if they have the same structure and the same values at each node.

Example:
Input: 
Tree1:     Tree2:
     1          1
    / \        / \
   2   3      2   3
  / \        / \
 4   5      4   5

Output: true
Explanation: Both trees have same structure and values

Constraints:
- The number of nodes in both trees is in the range [0, 100]
- -10^4 <= Node.val <= 10^4
*/

bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p == nullptr or q == nullptr) {
        return p == q;
    } else {
        return p->val == q->val 
            and (isSameTree(p->left, q->left) and isSameTree(p->right, q->right));
    }
}

// Driver code - do not modify
int main() {
    // Create first tree
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    p->left->left = new TreeNode(4);
    p->left->right = new TreeNode(5);
    
    // Create second tree
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    q->left->left = new TreeNode(4);
    q->left->right = new TreeNode(5);
    
    bool result = isSameTree(p, q);
    cout << "Are trees identical? " << (result ? "Yes" : "No") << endl;
    
    return 0;
}