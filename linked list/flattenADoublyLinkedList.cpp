#include <bits/stdc++.h>
using namespace std;

// Node class definition for doubly linked list with child pointer
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
    
    Node(int _val) {
        val = _val;
        prev = NULL;
        next = NULL;
        child = NULL;
    }
};

// Function to flatten a multilevel doubly linked list
Node* flatten(Node* head) {
    // Your implementation goes here
}

// Helper function to print the flattened list
void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a test multilevel linked list
Node* createMultilevelList() {
    /*
    Creates this structure:
    1 - 2 - 3 - 4
        |
        7 - 8 - 9
            |
            11 - 12
    */
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->child = new Node(7);
    head->next->child->next = new Node(8);
    head->next->child->next->prev = head->next->child;
    head->next->child->next->next = new Node(9);
    head->next->child->next->next->prev = head->next->child->next;

    head->next->child->next->child = new Node(11);
    head->next->child->next->child->next = new Node(12);
    head->next->child->next->child->next->prev = head->next->child->next->child;

    return head;
}

int main() {
    /*
    Input:
    1 - 2 - 3 - 4
        |
        7 - 8 - 9
            |
            11 - 12

    Expected Output:
    1 -> 2 -> 7 -> 8 -> 11 -> 12 -> 9 -> 3 -> 4
    */

    Node* head = createMultilevelList();
    cout << "Original multilevel list structure created" << endl;
    
    Node* flattened = flatten(head);
    
    cout << "Flattened list: ";
    printList(flattened);

    return 0;
}