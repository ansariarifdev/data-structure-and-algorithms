
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
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        // TODO: Implement level order traversal logic
        if(root == nullptr) {
            return {};
        }

        vector<vector<int>> ans;
        queue<TreeNode* > q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            vector<int> currentLevel;

            while(n--) {
                TreeNode* currentNode = q.front();
                q.pop();
                currentLevel.push_back(currentNode->val);

                if(currentNode->left) {
                    q.push(currentNode->left);
                }
                if(currentNode->right) {
                    q.push(currentNode->right);
                }
            }
            ans.push_back(currentLevel);
        }
        return ans;
    }

    // Helper function to clean up memory
    void deleteTree(TreeNode* root) {
        if (root == nullptr) return;
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
};

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    Solution solution;
    
    // Test level order traversal
    cout << "Level Order Traversal:\n";
    vector<vector<int>> result = solution.levelOrder(root);
    for(const auto& level : result) {
        for(int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    // Clean up memory
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}