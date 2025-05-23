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
    ListNode* middleNode(ListNode* head) {
        int n=0;
        struct ListNode *p=head;
        while (p!=NULL){
            p=p->next;
            n++;
        }
        int z=n/2;
        p=head;
        while (z--){
            p=p->next;
        }
        head=p;
        return head;
        
    }
};