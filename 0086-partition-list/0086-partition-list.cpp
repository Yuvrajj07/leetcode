class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
    ListNode *p=head;
    ListNode l1(0);  // storing larger elements than val
    ListNode l2(0); // storing small elements  than val
    ListNode* ll1=&l1;
    ListNode* ll2=&l2;
    while (p!=NULL){
        if (p->val <x){
            ll2->next=p;
            p=p->next;
            ll2=ll2->next;
        }
        else {
            ll1->next=p;
            p=p->next;
            ll1=ll1->next;
        }
    }
ll1->next=NULL;
ll2->next=l1.next;
return l2.next;
    }
};
        
        