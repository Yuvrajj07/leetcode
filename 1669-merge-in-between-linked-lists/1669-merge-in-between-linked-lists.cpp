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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *p1 = NULL, *p2 = NULL;
        ListNode *p = list1, *pp = NULL;
        int i = 0;
        while (p != NULL) {
            i++;
            if (i == a) {
                p1 = p;
            }
            if (i == b) {
                p2 = p->next;
                break;
            }
            p = p->next;
        }
        p1->next = list2;
        while (list2->next != NULL) {
            list2 = list2->next;
        }
        list2->next = p2->next;
        return list1;
    }
};