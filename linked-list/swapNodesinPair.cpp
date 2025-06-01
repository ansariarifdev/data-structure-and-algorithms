#include <bits/stdc++.h>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to swap nodes in pairs
ListNode* swapPairs(ListNode* head) {
    // Your implementation goes here
}

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from vector
ListNode* createList(vector<int> values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

int main() {
    /*
    Examples:
    1. Input:  1->2->3->4
       Output: 2->1->4->3
       
    2. Input:  1->2->3
       Output: 2->1->3 (last node remains as is)
       
    3. Input:  1
       Output: 1 (single node remains unchanged)
    */

    // Test case 1: Even number of nodes
    vector<int> values1 = {1, 2, 3, 4};
    ListNode* head1 = createList(values1);
    cout << "Original List 1: ";
    printList(head1);
    head1 = swapPairs(head1);
    cout << "After swapping: ";
    printList(head1);

    // Test case 2: Odd number of nodes
    vector<int> values2 = {1, 2, 3};
    ListNode* head2 = createList(values2);
    cout << "\nOriginal List 2: ";
    printList(head2);
    head2 = swapPairs(head2);
    cout << "After swapping: ";
    printList(head2);

    return 0;
}