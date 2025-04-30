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
    vector<int> topView(TreeNode* root) {
        if(root == nullptr) {
            return {};
        }

        queue<pair<TreeNode*, int>> nodeHorizontalDistance;
        nodeHorizontalDistance.push({root, 0});

        map<int, int> horizontalDistanceNodeValue;

        while(!nodeHorizontalDistance.empty()) {
            TreeNode* currentNode = nodeHorizontalDistance.front().first;
            int horizontalDistance = nodeHorizontalDistance.front().second;
            nodeHorizontalDistance.pop();

            if(horizontalDistanceNodeValue.find(horizontalDistance) == horizontalDistanceNodeValue.end()) {
                horizontalDistanceNodeValue[horizontalDistance] = currentNode->val;
            }
            
            if(currentNode->left) {
                nodeHorizontalDistance.push({currentNode->left, horizontalDistance-1});
            }
            if(currentNode->right) {
                nodeHorizontalDistance.push({currentNode->right, horizontalDistance+1});
            }
        }

        vector<int> ans;
        for(auto element: horizontalDistanceNodeValue) {
            ans.push_back(element.second);
        }
        return ans;
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
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    
    Solution solution;
    
    vector<int> result = solution.topView(root);
    cout << "Top view of tree: ";
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    solution.deleteTree(root);
    root = nullptr;
    
    return 0;
}