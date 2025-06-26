#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Your implementation here
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        while(fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if(hasCycle) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slow;
    }
};

// Helper to create a cycle in the linked list for testing
ListNode* createCycleList() {
    ListNode* head = new ListNode(3);
    ListNode* second = new ListNode(2);
    ListNode* third = new ListNode(0);
    ListNode* fourth = new ListNode(-4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;  // cycle starts at node with value 2

    return head;
}

int main() {
    Solution sol;
    ListNode* head = createCycleList();
    ListNode* startNode = sol.detectCycle(head);
    
    if (startNode)
        cout << "Cycle starts at node with value: " << startNode->val << endl;
    else
        cout << "No cycle detected." << endl;

    return 0;
}
