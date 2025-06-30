#include <iostream>
#include <vector>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* previous = nullptr;
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;

    // Implementation of the solve function
    void solve(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }
        
        solve(root->left);

        if(previous != nullptr and root->val < previous->val) {
            if(first == nullptr) {
                first = previous;
            }
            second = root;
        }

        previous = root;
        solve(root->right);
    }

    void recoverTree(TreeNode* root) {
        // Your implementation goes here
        solve(root);
        swap(first->val, second->val);
    }

    // Optional: Function to print inorder traversal and verify result
    void inorder(TreeNode* root) {
        if(root == nullptr) {
            return ;
        }

        inorder(root->left);
        cout << root->val << " ";
        inorder(root->right);
    }
};

int main() {
    /*
      Constructing a sample BST where two nodes are swapped:
      
          3
         / \
        1   4
           /
          2

      Correct BST should be:
      
          2
         / \
        1   4
           /
          3
    */

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);

    Solution().recoverTree(root);

    Solution().inorder(root); // Should print sorted sequence: 1 2 3 4
    return 0;
}
