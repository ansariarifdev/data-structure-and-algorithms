#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to return right view of binary tree
vector<int> rightView(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return {};
    }

    queue<TreeNode* > q;
    q.push(root);
    vector<int> ans;

    while(!q.empty()) {
        int n = q.size();
        
        for(int i = 0; i < n; i++) {
            TreeNode* currentNode = q.front();
            q.pop();
            if(i == n-1) {
                ans.push_back(currentNode->val);
            }
            if(currentNode->left) {
                q.push(currentNode->left);
            }
            if(currentNode->right) {
                q.push(currentNode->right);
            }
        }
    }
    return ans;
}

int main() {
    /*
         1
       /   \
      2     3
     / \   / \
    4   5 6   7
           \
            8

    Expected Right View: 1 3 7 8
    (Nodes visible when viewed from right side)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    vector<int> result = rightView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}