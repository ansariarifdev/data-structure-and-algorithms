#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to return top view of binary tree
vector<int> topView(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return {};
    }

    map<int, int> mp;
    queue<pair<TreeNode*, int>> q;
    
    q.push({root, 0});

    while(!q.empty()) {
        auto [currentNode, level] = q.front();
        q.pop();

        if(mp.find(level) == mp.end()) {
            mp[level] = currentNode->val;
        }

        if(currentNode->left) {
            q.push({currentNode->left, level -1});
        }
        if(currentNode->right) {
            q.push({currentNode->right, level + 1});
        }
    }

    vector<int> ans;
    for(auto element: mp) {
        ans.push_back(element.second);
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

    Expected Top View: 4 2 1 3 7
    (Nodes visible when viewed from top)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    vector<int> result = topView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}