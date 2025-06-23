#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int currentSmaller = 0;
// Function to find the kth smallest element in a BST
int kthSmallest(TreeNode* root, int k) {

    
}

int main() {
    // Example 1:
    //      3
    //     / \
    //    1   4
    //     \
    //      2
    // k = 1
    // Expected: 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(1);
    root1->right = new TreeNode(4);
    root1->left->right = new TreeNode(2);

    cout << "Example 1: " << kthSmallest(root1, 1) << endl;

    // Example 2:
    //      5
    //     / \
    //    3   6
    //   / \
    //  2   4
    // /
    //1
    // k = 3
    // Expected: 3
    TreeNode* root2 = new TreeNode(5);
    root2->left = new TreeNode(3);
    root2->right = new TreeNode(6);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(4);
    root2->left->left->left = new TreeNode(1);

    cout << "Example 2: " << kthSmallest(root2, 3) << endl;

    // Clean up memory
    delete root1->left->right;
    delete root1->left;
    delete root1->right;
    delete root1;

    delete root2->left->left->left;
    delete root2->left->left;
    delete root2->left->right;
    delete root2->left;
    delete root2->right;
    delete root2;

    return 0;
}