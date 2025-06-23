#include <iostream>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
pair<bool, int> solve(TreeNode* root) {
    if(root == nullptr) {
        return {true, 0};
    }
    if(root->left == nullptr and root->right == nullptr) {
        return {true, root->val};
    }

    auto leftAns = solve(root->left);
    auto rightAns = solve(root->right);

    
    if(!(leftAns.first and rightAns.first) or !(root->val == leftAns.second + rightAns.second)) {
        return {false, root->val};
    }
    return {true, root->val + leftAns.second + rightAns.second};

}
// Function to check if tree is Sum Tree
bool isSumTree(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return false;
    }

    return solve(root).first;
}

int main() {
    /*
         26
       /    \
     10      3
    /  \      \
   4    6      3

    Expected Output: true
    (Each node is sum of its left and right subtrees)
    Example:
    - 4 and 6 sum to 10
    - 3 is leaf node
    - 10 and 3 sum to 26
    */

    TreeNode* root = new TreeNode(26);
    root->left = new TreeNode(10);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(3);

    if (isSumTree(root)) {
        cout << "The tree is a Sum Tree" << endl;
    } else {
        cout << "The tree is not a Sum Tree" << endl;
    }

    return 0;
}