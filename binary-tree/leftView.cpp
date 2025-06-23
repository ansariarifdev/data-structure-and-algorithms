#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to return left view of binary tree
vector<int> leftView(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return {};
    }

    vector<int> ans;
    queue<TreeNode* > q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();

        for(int i = 0; i < n; i++) {
            TreeNode* currentNode = q.front();
            q.pop();

            if(i == 0) {
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

    Expected Left View: 1 2 4 8
    (Nodes visible when viewed from left side)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    vector<int> result = leftView(root);
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}