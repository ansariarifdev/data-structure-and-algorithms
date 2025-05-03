
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
    void solve(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }

        solve(root->left);
        solve(root->right);
        swap(root->left, root->right);
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr)    {
            return nullptr;
        }
        solve(root);
        return root;
    }

    void printLevelOrder(TreeNode* root) {
        if (root == nullptr) return;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int levelSize = q.size();
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                cout << node->val << " ";
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            cout << endl;
        }
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
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    
    Solution solution;
    
    cout << "Original tree:" << endl;
    solution.printLevelOrder(root);
    
    root = solution.invertTree(root);
    
    cout << "\nInverted tree:" << endl;
    solution.printLevelOrder(root);
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}




// Even simpler Implementation

/*
TreeNode* invertTree(TreeNode* root) {
    if(root == nullptr) {
        return nullptr;
    }

    invertTree(root->left);
    invertTree(root->right);
    swap(root->left, root->right);

    return root;
}

*/