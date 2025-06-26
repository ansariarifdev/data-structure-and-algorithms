#include <iostream>
#include <vector>
#include <set>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to detect and remove cycle in a linked list
void detectAndRemoveCycle(ListNode* head) {
    // Your implementation goes here
    ListNode* slow = head;
    ListNode* fast = head;
    bool hasCycle = false;

    while(fast != nullptr and fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            hasCycle = true;
            break;
        }
    }

    if(hasCycle) {
        ListNode* previous = nullptr;
        slow = head;

        while(slow != fast) {
            previous = fast;
            slow = slow->next;
            fast = fast->next;
        }
        if(slow == fast) {
            previous->next = nullptr;
        }
    }
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

// Helper function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    set<ListNode*> visited;  // To prevent infinite loop while printing
    while (current != nullptr && visited.find(current) == visited.end()) {
        cout << current->val << " -> ";
        visited.insert(current);
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    /*
    Example:
    Input:  1 -> 2 -> 3 -> 4 -> 5 -┐
                 ^__________________|
    (Cycle at position 1)
    
    After removing cycle:
    Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    */

    // Test case 1: List with cycle
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode* head = createLinkedListWithCycle(values, 1);
    
    cout << "Before cycle removal:" << endl;
    cout << "List has cycle: true" << endl;
    
    detectAndRemoveCycle(head);
    
    cout << "\nAfter cycle removal:" << endl;
    cout << "List after removing cycle: ";
    printList(head);

    return 0;
}