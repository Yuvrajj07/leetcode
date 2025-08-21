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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        multiset<int>m;
        for (int i =0;i<v.size();i++){
            ListNode *curr=v[i];
            while (curr!=NULL){
                m.insert(curr->val);
                curr=curr->next;
            }
        }
         if (m.empty()) return nullptr;
        ListNode *l1=new ListNode(*m.begin());
        ListNode *ans=l1;
        l1->next=NULL;
        m.erase(m.begin());
        while (m.size()>0){
            ListNode *l2=new ListNode(*m.begin());
            l1->next=l2;
            l1=l2;
            m.erase(m.begin());
        }
        return ans;
    }
};

