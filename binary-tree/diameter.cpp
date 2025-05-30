#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    
    static Node* createNode(int data) {
        return new Node(data);
    }
};

class Solution {
public:

    // Implementation of the height function 
    int height(Node* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return max(leftHeight, rightHeight) + 1;
    }
    
    int findDiameter(Node* root) {
        if(root == nullptr) {
            return 0;
        }

        int leftDiameter = findDiameter(root->left);
        int rightDiameter = findDiameter(root->right);
        int currentDiameter = height(root->left) + height(root->right);

        return max(currentDiameter, max(leftDiameter, rightDiameter));

    }
};

int main() {
    Node* root = Node::createNode(1);
    root->left = Node::createNode(2);
    root->right = Node::createNode(3);
    root->left->left = Node::createNode(4);
    root->left->right = Node::createNode(5);
    
    Solution solution;
    std::cout << "Diameter of the binary tree is: " << solution.findDiameter(root) << std::endl;
    
    return 0;
}