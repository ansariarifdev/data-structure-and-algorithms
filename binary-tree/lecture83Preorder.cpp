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

// Implementation of preorderHelper function 
void preorderHelper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return ;
    }

    result.push_back(root->val);
    preorderHelper(root->left, result);
    preorderHelper(root->right, result);

}

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        preorderHelper(root, result);
        return result;
    }

    vector<int> preorderTraversalIterative(TreeNode* root) {
        vector<int> result;
        stack<TreeNode* > st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* topNode = st.top();
            st.pop();
            result.push_back(topNode->val);

            if(topNode->right) {
                st.push(topNode->right);
            }
            
            if(topNode->left) {
                st.push(topNode->left);
            }
            
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
    vector<int> result = solution.preorderTraversal(root);
    cout << "Recursive Preorder: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test iterative approach
    result = solution.preorderTraversalIterative(root);
    cout << "Iterative Preorder: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}