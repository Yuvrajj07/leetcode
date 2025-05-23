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
    ListNode *reverse(ListNode *curr,ListNode *prev){
        if (curr==NULL) return prev;
        ListNode *forw=curr->next;
        curr->next=prev;
        prev=curr;
        return reverse(forw,prev);
        
    }
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head,*prev=NULL, *forw=NULL;
        return reverse(curr,NULL);
    }
};