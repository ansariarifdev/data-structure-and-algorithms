#include <bits/stdc++.h>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect cycle in a linked list
bool hasCycle(ListNode* head) {
    // Your implementation goes here
}

// Helper function to create a linked list with a cycle
ListNode* createLinkedListWithCycle(vector<int> values, int pos) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    ListNode* cycleNode = (pos == 0) ? head : nullptr;
    
    for (int i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
        if (i == pos) cycleNode = current;
    }
    
    if (pos >= 0) current->next = cycleNode;
    return head;
}

int main() {
    /*
    Example 1:
    3 -> 2 -> 0 -> -4 -┐
         ^______________|
    
    Has cycle: true (tail connects to position 1)

    Example 2:
    1 -> 2 -> 3 -> 4
    Has cycle: false (no cycle)
    */

    // Test case 1: List with cycle
    vector<int> values1 = {3, 2, 0, -4};
    ListNode* head1 = createLinkedListWithCycle(values1, 1);
    cout << "List 1 has cycle: " << (hasCycle(head1) ? "true" : "false") << endl;

    // Test case 2: List without cycle
    vector<int> values2 = {1, 2, 3, 4};
    ListNode* head2 = createLinkedListWithCycle(values2, -1);
    cout << "List 2 has cycle: " << (hasCycle(head2) ? "true" : "false") << endl;

    return 0;
}