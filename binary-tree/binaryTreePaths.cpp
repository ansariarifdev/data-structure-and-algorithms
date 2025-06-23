#include <iostream>
#include <vector>
#include <string>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
void solve(TreeNode* root, string path, vector<string> &ans) {
    if(root == nullptr) {
        return ;
    }
    if(root->left == nullptr and root->right == nullptr) {
        path += to_string(root->val);
        ans.push_back(path);
        return ;
    }
    path += to_string(root->val) + "->" ;
    solve(root->left, path, ans);
    solve(root->right, path, ans);
}

// Function to return all root-to-leaf paths
vector<string> binaryTreePaths(TreeNode* root) {
    if(root == nullptr) {
        return {};
    }

    vector<string> ans;
    string path = "";
    solve(root, path, ans);
    return ans;
}

int main() {
    /*
         1
       /   \
      2     3
       \
        5

    Expected Output: ["1->2->5", "1->3"]
    All possible paths:
    Path 1: 1 -> 2 -> 5
    Path 2: 1 -> 3
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    vector<string> paths = binaryTreePaths(root);
    
    cout << "All root-to-leaf paths:" << endl;
    for (const string& path : paths) {
        cout << path << endl;
    }

    return 0;
}