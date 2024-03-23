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
    void reorderList(ListNode* head) {
        vector<int>ans;
         ListNode *p=head;
        while (p!=NULL){
            ans.push_back(p->val);
            p=p->next;
        }
        int i=0,j=ans.size()-1;
         p=head;
         int c=0;
         while (p!=NULL){
            if (c%2==0){
            p->val=ans[i];
            i++;
            c++;
            }
            else {
                p->val=ans[j];
                j--;
                c++;
            }
            p=p->next;

         }

        }
};
