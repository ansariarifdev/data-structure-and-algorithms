
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    // Implementation of the height function 
    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
    // Implementation of solve function 
    void solve(TreeNode* root, int k, vector<int> &ans) {
        if(root == nullptr) {
            return ;
        }
        if(k == 0) {
            ans.push_back(root->val);
        }

        solve(root->left, k-1, ans);
        solve(root->right, k-1, ans);
    }
    vector<int> kthLevel(TreeNode* root, int k) {
        if(root == nullptr or k < 0) {
            return {};
        }
        if(k == 0) {
            return {root->val};
        }
        if(k >= height(root)) {
            return {};
        }

        vector<int> ans;
        solve(root, k, ans);
        return ans;

    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    
    Solution solution;
    
    int k = 2; // Level to find (0-based indexing)
    vector<int> result = solution.kthLevel(root, k);
    
    cout << "Nodes at level " << k << ": ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}