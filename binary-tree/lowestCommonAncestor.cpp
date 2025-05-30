#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find the lowest common ancestor of two nodes
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    // Your implementation goes here
    if(root == nullptr ) {
        return nullptr;
    }
    if(root->val == p->val or root->val == q->val) {
        return root;
    }

    TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

    if(leftAns and rightAns) {
        return root;
    } else {
        return (leftAns) ? leftAns : rightAns;
    }
}

int main() {
    /*
         3
       /   \
      5     1
     / \   / \
    6   2 0   8
       / \
      7   4

    Example test cases:
    1. LCA(5, 1) = 3
    2. LCA(5, 4) = 5
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    // Test case 1: LCA of nodes 5 and 1
    TreeNode* p1 = root->left;      // node with value 5
    TreeNode* q1 = root->right;     // node with value 1
    TreeNode* result1 = lowestCommonAncestor(root, p1, q1);
    cout << "LCA of 5 and 1 is: " << result1->val << endl;

    // Test case 2: LCA of nodes 5 and 4
    TreeNode* p2 = root->left;                  // node with value 5
    TreeNode* q2 = root->left->right->right;    // node with value 4
    TreeNode* result2 = lowestCommonAncestor(root, p2, q2);
    cout << "LCA of 5 and 4 is: " << result2->val << endl;

    return 0;
}