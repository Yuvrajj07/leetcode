/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) return NULL;

        ListNode *slow = head, *fast = head;

        // Step 1: Detect cycle using two pointers
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) { // Cycle detected
                slow = head;
                while (slow != fast) { // Finding cycle start
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow; // Cycle starts here
            }
        }
        return NULL; // No cycle found
    }
};
