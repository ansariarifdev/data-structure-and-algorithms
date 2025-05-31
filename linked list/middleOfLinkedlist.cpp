#include <bits/stdc++.h>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to find middle node of linked list
ListNode* middleNode(ListNode* head) {
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
    Example 1:
    Input: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Output: 3 -> 4 -> 5 -> NULL (middle node is 3)

    Example 2:
    Input: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
    Output: 4 -> 5 -> 6 -> NULL (middle node is 4)

    Note: When the list has even length, return the second middle node
    */

    // Test case 1: Odd length list
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Original List 1: ";
    printList(head1);
    cout << "Middle onwards: ";
    printList(middleNode(head1));

    // Test case 2: Even length list
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout << "\nOriginal List 2: ";
    printList(head2);
    cout << "Middle onwards: ";
    printList(middleNode(head2));

    return 0;
}