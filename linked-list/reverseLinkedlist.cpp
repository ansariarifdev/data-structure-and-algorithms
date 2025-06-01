#include <bits/stdc++.h>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse a linked list
ListNode* reverseList(ListNode* head) {
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

int main() {
    /*
    Original List: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Expected Output: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    
    Process:
    1. Original: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    2. Reverse each pointer
    3. Final: 5 -> 4 -> 3 -> 2 -> 1 -> NULL
    */

    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}