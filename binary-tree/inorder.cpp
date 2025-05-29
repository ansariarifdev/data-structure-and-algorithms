#include <iostream>
#include <vector>
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
Problem: Implement inorder traversal of a binary tree
Expected Output for sample tree:
     1
    / \
   2   3
  / \
 4   5
Should print: 4 2 5 1 3
*/

// Implementation of the solve function 
void solve(TreeNode* root, vector<int> &ans) {
    if(root == nullptr) {
        return ;
    }

    solve(root->left, ans);
    ans.push_back(root->val);
    solve(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
    // Write your solution here
    if(root == nullptr) {
        return {};
    }

    vector<int> ans;
    solve(root, ans);
    return ans;
}

// Driver code
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<int> result = inorderTraversal(root);
    
    cout << "Inorder traversal: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}