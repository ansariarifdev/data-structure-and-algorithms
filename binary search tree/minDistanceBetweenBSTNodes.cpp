#include <iostream>
#include <climits>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
void solve(TreeNode* root, int &previous, int &minDifference) {
    if(root == nullptr) {
        return ;
    }

    solve(root->left, previous, minDifference);

    if(previous != -1) {
        minDifference = min(minDifference, root->val - previous);
    }
    previous = root->val;

    solve(root->right, previous, minDifference);
}

// User implements this function
int getMinimumDifference(TreeNode* root) {
    int previous = -1;
    int minDifference = INT_MAX;

    solve(root, previous, minDifference);
    return minDifference;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else if (val > root->val)
        root->right = insert(root->right, val);
    return root;
}

int main() {
    // Build BST: [4, 2, 6, 1, 3]
    TreeNode* root = nullptr;
    vector<int> values = {4, 2, 6, 1, 3};
    for (int val : values)
        root = insert(root, val);

    int result = getMinimumDifference(root);
    cout << "Minimum absolute difference: " << result << endl;

    // In-order traversal: 1, 2, 3, 4, 6
    // Min differences: (2-1)=1, (3-2)=1, (4-3)=1, (6-4)=2
    // ✅ Expected Output: 1

    return 0;
}
