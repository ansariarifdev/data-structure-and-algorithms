#include <bits/stdc++.h>
using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
int findRoot(vector<int> &inorder, int value, int start, int end) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

// Implementation of the solve function 
TreeNode* solve(vector<int> &preorder, vector<int> &inorder, int &preorderIndex, int start, int end) {
    if(start > end) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preorderIndex]);
    preorderIndex++;

    int index = findRoot(inorder, root->val, start, end);
    root->left = solve(preorder, inorder, preorderIndex, start, index-1);
    root->right = solve(preorder, inorder, preorderIndex, index+1, end);

    return root;
}
// Function to build tree from inorder and preorder traversals
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    // Your implementation goes here
    int preorderIndex = 0;
    return solve(preorder, inorder, preorderIndex, 0, preorder.size()-1);
}

// Helper function to print tree in inorder (for verification)
void printInorder(TreeNode* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    /*
    Example Tree:
         3
       /   \
      9     20
           /  \
          15   7

    Preorder traversal: [3,9,20,15,7]
    Inorder traversal:  [9,3,15,20,7]
    */

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode* root = buildTree(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}