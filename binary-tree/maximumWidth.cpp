#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to find maximum width of binary tree
int maxWidth(TreeNode* root) {
    // Your implementation goes here
    if(root == nullptr) {
        return 0;
    }

    int maxWidth = 0;
    queue<pair<TreeNode* , unsigned long long>> q;
    q.push({root, 0});

    while(!q.empty()) {
        int n = q.size();
        unsigned long long leftIndex = q.front().second;
        unsigned long long rightIndex = q.back().second;

        maxWidth = max(maxWidth, (int)(rightIndex - leftIndex + 1));

        for(int i = 0; i < n; i++) {
            auto [currentNode, index] = q.front();
            q.pop();

            if(currentNode->left) {
                q.push({currentNode->left, 2*index+1});
            }
            if(currentNode->right) {
                q.push({currentNode->right, 2*index + 2});
            }
        }
    }
    return maxWidth;
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

    Expected Output: 4
    (Maximum width is 4 at the level of nodes 4,5,6,7)
    Level-wise width:
    Level 0: 1 node (width = 1)
    Level 1: 2 nodes (width = 2)
    Level 2: 4 nodes (width = 4) <- maximum width
    Level 3: 1 node (width = 1)
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);

    int result = maxWidth(root);
    cout << "Maximum width of the binary tree is: " << result << endl;

    return 0;
}