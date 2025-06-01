#include <bits/stdc++.h>
using namespace std;

// ListNode definition
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Function to merge two sorted linked lists
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
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
    List1: 1 -> 2 -> 4
    List2: 1 -> 3 -> 4
    
    Expected Output: 1 -> 1 -> 2 -> 3 -> 4 -> 4
    
    Process:
    1. Compare nodes from both lists
    2. Add smaller value to result
    3. Move pointer of used value forward
    4. Repeat until both lists are exhausted
    */

    vector<int> values1 = {1, 2, 4};
    vector<int> values2 = {1, 3, 4};
    
    ListNode* list1 = createList(values1);
    ListNode* list2 = createList(values2);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);

    ListNode* merged = mergeTwoLists(list1, list2);
    
    cout << "Merged List: ";
    printList(merged);

    return 0;
}