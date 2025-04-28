
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
    // Recursive approach
    int findMax(TreeNode* root) {
       if(root == nullptr) {
        return INT_MIN; 
       }

       int leftAns = findMax(root->left);
       int rightAns = findMax(root->right);

       return max(root->val, max(leftAns, rightAns));
    }
    
    // Iterative approach using level order traversal
    int findMaxIterative(TreeNode* root) {
        // TODO: Implement the logic to find maximum value iteratively
        if(root == nullptr) {
            return INT_MIN;
        }
        int ans = INT_MIN;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* frontNode = q.front();
            q.pop();

            ans = max(ans, frontNode->val);

            if(frontNode->left) {
                q.push(frontNode->left);
            }
            if(frontNode->right) {
                q.push(frontNode->right);
            }
        }
        return ans;
    }

    void deleteTree(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }

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
    cout << "Maximum value (Recursive): " << solution.findMax(root) << endl;
    
    // Test iterative approach
    cout << "Maximum value (Iterative): " << solution.findMaxIterative(root) << endl;
    

    solution.deleteTree(root);
    root = nullptr;
    return 0;
}