#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    // Implementation of the solve function 
    TreeNode* solve(vector<int>& preorder, int &index, int upperBound) {
        if(index >= preorder.size() or preorder[index] >= upperBound) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        root->left = solve(preorder, index, root->val);
        root->right = solve(preorder, index, upperBound);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // Implement your logic here
        int i = 0;
        return solve(preorder, i, INT_MAX);
    }
};

// Utility function to print tree in-order
void inOrder(TreeNode* root) {
    if (!root) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main() {
    Solution sol;

    // Example 1
    vector<int> preorder1 = {8, 5, 1, 7, 10, 12};
    TreeNode* root1 = sol.bstFromPreorder(preorder1);
    cout << "In-order of BST 1: ";
    inOrder(root1);  // Expected Output: 1 5 7 8 10 12
    cout << endl;

    // Example 2
    vector<int> preorder2 = {1, 0, 2};
    TreeNode* root2 = sol.bstFromPreorder(preorder2);
    cout << "In-order of BST 2: ";
    inOrder(root2);  // Expected Output: 0 1 2
    cout << endl;

    return 0;
}
