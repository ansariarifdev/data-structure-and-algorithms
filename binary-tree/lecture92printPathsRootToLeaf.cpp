
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
    // Implementation of the solve function 
    void solve(TreeNode* root, string currentPath, vector<string> &ans) {
        if(root->left == nullptr and root->right == nullptr) {
            ans.push_back(currentPath);
            return ;
        }

        if(root->left) {
            solve(root->left, currentPath+"->"+to_string(root->left->val), ans);
        }
        if(root->right) {
            solve(root->right, currentPath+"->"+to_string(root->right->val), ans);
        }

        /*
        Remember: 
        
            If the currentPath is passed by reference, we need to delete the 
            last added node value(as string while backtracking)

            but since it is passed by value, at each recursive function call , it creates its own 
            copy for the next stage(handling the function call)
            and during backtracking , it automatically , works for its previous state(the one before that function call )

        */
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        string currentPath = to_string(root->val);
        vector<string> ans;
        solve(root, currentPath, ans);
        
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
    // Create test tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    
    vector<string> paths = solution.binaryTreePaths(root);
    
    cout << "All root to leaf paths:" << endl;
    for(const string& path : paths) {
        cout << path << endl;
    }
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}