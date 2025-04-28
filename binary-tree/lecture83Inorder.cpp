#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Implementation of inorderHelper function 
void inorderHelper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return;
    }
    
    inorderHelper(root->left, result);    // Process left
    result.push_back(root->val);          // Process root
    inorderHelper(root->right, result);   // Process right
}

// Implementation of inorderHelper function 
void inorderHleper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return ;
    }

    inorderHelper(root->left, result);
    result.push_back(root->val);
    inorderHelper(root->right, result);
}

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    vector<int> inorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode* > st;
        TreeNode* current = root;

        while(current or !st.empty()) {
            while(current) {
                st.push(current);
                current = current->left;
            }
            current = st.top();
            st.pop();

            result.push_back(current->val);

            current = current->right;
        }
        return result;
    }
    
};

// Driver code for testing
int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    
    // Test recursive approach
    vector<int> result = solution.inorderTraversal(root);
    cout << "Recursive Inorder: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test iterative approach
    result = solution.inorderTraversalIterative(root);
    cout << "Iterative Inorder: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}