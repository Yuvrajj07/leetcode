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
    bool hasCycle(ListNode *head) {
        struct ListNode *p=head;
        if (p==NULL || p->next==NULL){
            return false;
        }
        struct ListNode *p2=head->next;
        
        while (p!=NULL && p2!=NULL && p2->next!=NULL){
            if (p==p2){
                return true;
            }
            p=p->next;
            p2=p2->next->next;

        }
        return false;
    }
};