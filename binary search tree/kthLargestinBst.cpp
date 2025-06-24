#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

// Implementation of the solve function 
void solve(TreeNode* root, int k, int &count, int &largest) {
    if(root == nullptr or largest != -1) {
        return;
    }

    solve(root->right, k, count, largest);

    count++;
    if(count == k) {
        largest = root->val;
        return ;
    }

    solve(root->left, k, count, largest);
}

// User implements this function
int kthLargest(TreeNode* root, int k) {
    int count = 0;
    int largest = -1;

    solve(root, k, count, largest);
    return largest;
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
    // Build BST
    TreeNode* root = nullptr;
    int values[] = {5, 3, 6, 2, 4, 1};
    for (int val : values)
        root = insert(root, val);

    int k = 2; // Looking for the 2nd largest element

    int result = kthLargest(root, k);
    cout << "Kth Largest Element (k = " << k << "): " << result << endl;

    // Expected in reverse in-order: 6, 5, 4, 3, 2, 1
    // So 2nd largest = 5
    // Expected Output: 5
}
