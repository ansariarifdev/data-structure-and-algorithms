#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// User implements this function
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root == nullptr) {
        return nullptr;
    } 

    if(p->val < root->val and q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else if(p->val > root->val and q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }

}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

TreeNode* findNode(TreeNode* root, int val) {
    if (!root) return nullptr;
    if (root->val == val) return root;
    if (val < root->val) return findNode(root->left, val);
    return findNode(root->right, val);
}

int main() {
    TreeNode* root = nullptr;
    int values[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int val : values)
        root = insert(root, val);

    TreeNode* p = findNode(root, 2);
    TreeNode* q = findNode(root, 8);

    TreeNode* lca = lowestCommonAncestor(root, p, q);

    if (lca)
        cout << "LCA of " << p->val << " and " << q->val << " is: " << lca->val << endl;
    else
        cout << "LCA not found." << endl;

    return 0;
}

/*
Iterative approach to solve this problem 

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val)
            root = root->left;
        else if (p->val > root->val && q->val > root->val)
            root = root->right;
        else
            return root;
    }
    return nullptr;
}
*/