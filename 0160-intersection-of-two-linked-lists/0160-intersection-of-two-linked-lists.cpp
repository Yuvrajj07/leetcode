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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return NULL;  // Edge case: if any list is empty
        
        ListNode *p1 = headA, *p2 = headB;
        
        while (p1 != p2) {  // Run until both pointers meet
            p1 = (p1 == NULL) ? headB : p1->next;  // Switch to headB when p1 reaches NULL
            p2 = (p2 == NULL) ? headA : p2->next;  // Switch to headA when p2 reaches NULL
        }
        
        return p1;  // If intersection exists, p1 == p2; otherwise, both are NULL
    }
};



// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         // set<Listnode>s1;
//           unordered_set<ListNode*> s;

//         ListNode *p1=headA,*p2=headB;
//         while (p1!=NULL){
//             s.insert(p1);
//             p1=p1->next;
//         }
//         while (p2!=NULL){
//             int z=s.size();
//             s.insert(p2);
//             int z1=s.size();
//             if (z1==z) return p2;
//             p2=p2->next;
//         }
//         return p1;
//     }
// };
