/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* rotateRight(ListNode* head, int k) {
//         struct ListNode *rev=NULL;
//         while (k--){
//             struct ListNode *p=head;
            
//             while (p->next!=NULL){
//                 rev=p->next;
//                 p=p->next;
//             }
//             p->next=NULL;
//             rev->next=head;
            
//         }
//         return rev;
//     }
// };

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || k == 0) {
            return head; // No rotation needed
        }

        int length = 1;
        ListNode* tail = head;

        // Calculate the length of the list and find the tail node
        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        // Adjust k to be within the range of the list length
        k = k % length;
        if (k == 0) {
            return head; // No rotation needed
        }

        // Find the (length - k)th node from the beginning
        ListNode* newTail = head;
        for (int i = 0; i < length - k - 1; i++) {
            newTail = newTail->next;
        }

        // Break the list at this point and reconnect the end of the list to the original head
        tail->next = head;
        head = newTail->next;
        newTail->next = nullptr;

        return head;
    }
};
