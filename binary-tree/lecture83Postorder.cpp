
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

// Implementation of the postorderHelper function 
void postorderHelper(TreeNode* root, vector<int> &result) {
    if(root == nullptr) {
        return ;
    }

    postorderHelper(root->left, result);
    postorderHelper(root->right, result);
    result.push_back(root->val);
}

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        postorderHelper(root, result);
        return result;
    }

    vector<int> postorderTraversalIterative(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        vector<int> result;
        stack<TreeNode* > st1, st2;
        st1.push(root);

        while(!st1.empty()) {
            TreeNode* current = st1.top();
            st1.pop();
            st2.push(current);

            if(current->left) {
                st1.push(current->left);
            }
            if(current->right) {
                st1.push(current->right);
            }
        }
        while(!st2.empty()) {
            result.push_back(st2.top()->val);
            st2.pop();
        }
        return result;
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
    vector<int> result = solution.postorderTraversal(root);
    cout << "Recursive Postorder: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    // Test iterative approach
    result = solution.postorderTraversalIterative(root);
    cout << "Iterative Postorder: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}