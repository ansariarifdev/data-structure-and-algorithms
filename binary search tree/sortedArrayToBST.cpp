#include <iostream>
#include <vector>
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
    TreeNode* solve(vector<int> &nums, int start, int end) {
        if(start > end) {
            return nullptr;
        }

        int midIndex = start + (end - start)/2;
        TreeNode* root = new TreeNode(nums[midIndex]);

        root->left = solve(nums, start, midIndex -1);
        root->right = solve(nums, midIndex + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Implement your logic here
        return solve(nums, 0, nums.size()-1);
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
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = sol.sortedArrayToBST(nums1);
    cout << "In-order of BST 1: ";
    inOrder(root1);  // Expected Output: -10 -3 0 5 9
    cout << endl;

    // Example 2
    vector<int> nums2 = {1, 3};
    TreeNode* root2 = sol.sortedArrayToBST(nums2);
    cout << "In-order of BST 2: ";
    inOrder(root2);  // Expected Output: 1 3 or 3 1 (both are valid BSTs)
    cout << endl;

    return 0;
}
