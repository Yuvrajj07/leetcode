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
    // void reverse(ListNode *start,ListNode *end){
    //       if (!start || !end) return;  // safety
    //     ListNode *curr=start->next,*prev=NULL,*forw=NULL,*lhead=start->next;
    //     while (curr!=end->next){
    //         forw=curr->next;
    //         curr->next=prev;
    //         prev=curr;
    //         curr=forw;
    //     }
    //     start->next=prev;
    //     lhead->next=curr;
    // }
    void reverse(ListNode *start, ListNode *end) {
        if (!start || !end) return;  // safety

        ListNode *curr = start->next, *prev = nullptr, *forw = nullptr;
        ListNode *lhead = start->next;   
        ListNode *stop = end->next;      

        while (curr != stop) {
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        start->next = prev;  
        lhead->next = stop;  
    }


    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // ListNode *start=NULL,*end=NULL,*curr=head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }
        ListNode* end = prev->next;
        for (int i = left; i < right; i++) {
            end = end->next;
        }
        reverse(prev,end);
        return dummy.next;      
    }
};