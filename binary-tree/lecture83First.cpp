#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left;
        TreeNode* right;

        TreeNode(int value) {
            data = value;
            left = right = nullptr;
        }
};

// Implementation of the buildTree function 
TreeNode* buildTree(vector<int> &preorder, int &index) {
    index++;
    if(preorder[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[index]);
    root->left = buildTree(preorder, index);
    root->right = buildTree(preorder, index);

    return root;
}

int main() {
    vector<int> preorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int index = -1;
    TreeNode* root = buildTree(preorder, index);

    cout << root->data << endl;
    cout << root->left->data << " " << root->right->data << endl;
    cout << "code is successfully ran " << endl;;
    
    return 0;
}