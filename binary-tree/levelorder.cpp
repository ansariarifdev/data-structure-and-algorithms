
#include <iostream>
#include <vector>
#include <queue>
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
Problem Statement: Binary Tree Level Order Traversal
Given the root of a binary tree, return the level order traversal of its nodes' values 
(i.e., from left to right, level by level).

Example:
Input: root = [1,2,3,4,5]
Tree Structure:
     1
    / \
   2   3
  / \
 4   5

Output: [[1],[2,3],[4,5]]

Constraints:
- The number of nodes in the tree is in the range [0, 2000]
- -1000 <= Node.val <= 1000
*/

vector<vector<int>> levelOrder(TreeNode* root) {
    if(root == nullptr) {
        return {};
    }

    vector<vector<int>> ans;
    queue<TreeNode* > q;
    q.push(root);

    while(!q.empty()) {
        int n = q.size();
        vector<int> currentLevel;

        for(int i = 0; i < n; i++) {
            TreeNode* currentNode = q.front();
            q.pop();
            currentLevel.push_back(currentNode->val);

            if(currentNode->left) {
                q.push(currentNode->left);
            }
            if(currentNode->right) {
                q.push(currentNode->right);
            }
        }
        ans.push_back(currentLevel);
    }
    return ans;
}

// Driver code - do not modify
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    vector<vector<int>> result = levelOrder(root);
    
    cout << "Level order traversal: \n";
    for(const auto& level : result) {
        cout << "[";
        for(int num : level) {
            cout << num << " ";
        }
        cout << "]\n";
    }
    
    return 0;
}