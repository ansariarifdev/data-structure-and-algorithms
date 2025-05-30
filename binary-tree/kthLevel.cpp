#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
void solve(TreeNode* root, int k, vector<int> &ans) {
    if(root == nullptr) {
        return ;
    }
    if(k == 0) {
        ans.push_back(root->val);
        return ;
    }

    solve(root->left, k-1, ans);
    solve(root->right, k-1, ans);
}
// Function to return nodes at kth level of binary tree 
vector<int> kthLevel(TreeNode* root, int k) {
    // Your implementation goes here
    vector<int> ans;
    solve(root, k, ans);
    return ans;
}

int main() {
    /*
         1            Level 0
       /   \
      2     3         Level 1
     / \   / \
    4   5 6   7       Level 2
           \
            8         Level 3

    Example test cases:
    k = 2: Expected Output: 4 5 6 7 (all nodes at level 2)
    k = 1: Expected Output: 2 3 (all nodes at level 1)
    k = 3: Expected Output: 8 (all nodes at level 3)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    int k = 2; // Change this value to get different level nodes
    vector<int> result = kthLevel(root, k);
    
    cout << "Nodes at level " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}