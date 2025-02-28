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
    ListNode* deleteMiddle(ListNode* head) {
        if (head->next==NULL){
            return NULL;
        }
        int n=0;
        ListNode *p=head;
        while (p!=NULL){
            p=p->next;
            n++;
        }
        int z=(n/2);
        int c=1;
        ListNode *p1=head;
        while (c!=z && p1->next!=NULL){
            p1=p1->next;
            c++;
        }
        ListNode *st=NULL;
        if (p1->next!=NULL)
        st=p1->next->next;
        else  st=NULL;
        p1->next=st;
        
        return head;
    }
};