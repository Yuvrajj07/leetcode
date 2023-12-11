// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
    
//         struct ListNode *p=head;
//         while(p!=NULL){
//             if (p->next==NULL) break;
//             int data1=p->val;
//             int data2=p->next->val;
//             p->val=data2;
//             p->next->val=data1;
//             p=p->next;
//             p=p->next;
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0); // Create a dummy node
        dummy->next = head;
        ListNode* current = dummy;

        while (current->next != nullptr && current->next->next != nullptr) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;

            // Swapping
            first->next = second->next;
            current->next = second;
            current->next->next = first;
            
            // Move current two steps forward
            current = current->next->next;
        }

        head = dummy->next;
        delete dummy; // Free the dummy node
        return head;
    }
};
