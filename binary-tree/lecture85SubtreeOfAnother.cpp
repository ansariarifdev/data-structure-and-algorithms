
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
    bool isIdentical(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr or root2 == nullptr) {
            return root1 == root2;
        }

        bool leftAns = isIdentical(root1->left, root2->left);
        bool rightAns = isIdentical(root1->right, root2->right);
        return (leftAns and rightAns) and (root1->val == root2->val);
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr or subRoot == nullptr){
            return root == subRoot;
        }
        if(root->val == subRoot->val and isIdentical(root, subRoot)) {
            return true;
        }
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);

    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create main tree
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    
    // Create subtree to check
    TreeNode* subRoot = new TreeNode(4);
    subRoot->left = new TreeNode(1);
    subRoot->right = new TreeNode(2);
    
    Solution solution;
    
    cout << "Is subtree? " << (solution.isSubtree(root, subRoot) ? "Yes" : "No") << endl;
    
    solution.deleteTree(root);
    solution.deleteTree(subRoot);
    root = nullptr;
    subRoot = nullptr;
    
    return 0;
}