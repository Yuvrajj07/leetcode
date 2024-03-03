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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int x=1;
        int size=0;
        struct ListNode *p=head;
        while (p!=NULL){
            size++;
            p=p->next;
        }
        if (n == size) {
            head = head->next;
            delete p;
            return head;
        }
        p=head;

        while (p!=NULL && x<=size-n-1){
                 p=p->next;
                 x++;
            }
           ListNode *ptr=p->next;
           p->next=p->next->next;
           delete(ptr);
             return head;
        }
};