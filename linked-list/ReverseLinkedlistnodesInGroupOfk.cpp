#include <iostream>
#include <vector>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to reverse nodes in groups of k
ListNode* reverseKGroup(ListNode* head, int k) {
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
    Example:
    Input: 1->2->3->4->5->6->7->8, k = 3
    
    Process:
    First group (1,2,3) -> reverse -> 3->2->1
    Second group (4,5,6) -> reverse -> 6->5->4
    Remaining nodes (7,8) -> less than k, leave as is
    
    Output: 3->2->1->6->5->4->7->8

    Note: If a group has less than k nodes, 
          don't reverse it (leave as is)
    */

    vector<int> values = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    
    ListNode* head = createList(values);
    
    cout << "Original List: ";
    printList(head);
    
    head = reverseKGroup(head, k);
    
    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}