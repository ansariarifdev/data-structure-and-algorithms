
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
    int sumOfNodes(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftSum = sumOfNodes(root->left);
        int rightSum = sumOfNodes(root->right);
        return root->val + leftSum + rightSum;
    }

    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    
    cout << "Sum of nodes: " << solution.sumOfNodes(root) << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}