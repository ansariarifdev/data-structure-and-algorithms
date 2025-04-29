
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
    int height(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        return max(leftHeight, rightHeight) + 1;
    }
    
    int diameter(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        
        int leftDiameter = diameter(root->left);
        int rightDiameter = diameter(root->right);
        int currentDaimeter = height(root->left) + height(root->right);

        return max(currentDaimeter, max(leftDiameter, rightDiameter));
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
    
    Solution solution;
    
    cout << "Diameter of tree: " << solution.diameter(root) << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}


// Optimised implimentation for the above problem: diameter of a binary tree
/*
int ans = 0;

// Implementation of the height function 
int height(TreeNode* root) {
    if(root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    ans = max(ans, leftHeight + rightHeight);
    return 1 + max(leftHeight, rightHeight);
}

int diameter(TreeNode* root) {
    height(root);
    return ans;
}

*/