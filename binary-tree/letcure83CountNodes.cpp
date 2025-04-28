
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
    
    int countNodes(TreeNode* root) {
        // TODO: Implement recursive counting logic
        if(root == nullptr) {
            return 0;
        }

        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return leftCount + rightCount + 1;
    }
    
    
    int countNodesIterative(TreeNode* root) {
        // TODO: Implement iterative counting logic using queue
        if(root == nullptr) {
            return 0;
        }
        
        int ans = 0;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* frontNode = q.front();
            q.pop();
            ans++;

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }
        return ans;
    }

    // Helper function to clean up memory
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    
    // Test recursive approach
    cout << "Total nodes (Recursive): " << solution.countNodes(root) << endl;
    
    // Test iterative approach
    cout << "Total nodes (Iterative): " << solution.countNodesIterative(root) << endl;
    
    // Clean up memory
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}