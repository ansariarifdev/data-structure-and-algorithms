#include <iostream> 
#include <vector>
using namespace std;

class Node {
    public:
        int val;
        Node* left;
        Node* right;

        Node(int data) {
            val = data;
            left = nullptr;
            right = nullptr;
        }
};

static int index = -1;

Node* buildTree(vector<int> &preOrder) {
    index++;

    if(preOrder[index] == -1) {
        return nullptr;
    }

    Node* root = new Node(preOrder[index]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);

    return root;
}

int main() {
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = buildTree(preOrder);
    cout << root->val << endl;

    return 0;
}