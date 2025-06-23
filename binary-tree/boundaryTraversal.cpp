#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Implementation of the printRightBoundary function
void printRightBoundary(TreeNode* root, vector<int> &ans) {
    if(root == nullptr or (root->left == nullptr and root->right == nullptr)) {
        return ;
    }
    printRightBoundary(root->right, ans);
    if(root->left) {
        printRightBoundary(root->left, ans);
    }
    ans.push_back(root->val);
}
// Implementation of the printLeaves function 
void printLeaves(TreeNode* root, vector<int> &ans) {
    if(root == nullptr) {
        return ;
    }

    if(root->left == nullptr and root->right == nullptr) {
        ans.push_back(root->val);
    }
    printLeaves(root->left, ans);
    printLeaves(root->right, ans);
}

// Implementation of the printLeftBoundary function 
void printLeftBoundary(TreeNode* root, vector<int> &ans) {
    if(root == nullptr or (root->left == nullptr and root->right == nullptr)) {
        return ;
    }
    ans.push_back(root->val);
    printLeftBoundary(root->left, ans);
    if(root->right) {
        printLeftBoundary(root->right, ans);
    }
}

// Function to return top view of binary tree
vector<int> topView(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return {};
    }

    vector<int> ans;
    printLeftBoundary(root, ans);
    printLeaves(root->left, ans);
    printLeaves(root->right, ans);
    printRightBoundary(root->right, ans);

    return ans;
}

int main() {
    /*
         1
       /   \
      2     3
     / \   
    4   5   

    Expected Top View: 4 2 1 3
    (Nodes visible when viewed from top, from leftmost to rightmost)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> result = topView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}