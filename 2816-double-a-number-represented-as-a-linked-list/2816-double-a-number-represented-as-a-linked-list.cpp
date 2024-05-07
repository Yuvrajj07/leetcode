// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        ListNode *p = head;
        stack <ListNode*> st;
        while (p != nullptr) {
            st.push(p);
            p = p->next;
        }
        int carry = 0;
        ListNode* resultList = nullptr;
        while (!st.empty()) {
            p = st.top();
            st.pop();
            int doubledValue = 2 * p->val + carry;
            p->val = doubledValue % 10;
            carry = doubledValue / 10;
            ListNode* newNode = new ListNode(p->val);
            newNode->next = resultList;
            resultList = newNode;
        }
        if (carry > 0) {
            ListNode* newNode = new ListNode(carry);
            newNode->next = resultList;
            resultList = newNode;
        }
        return resultList;
    }
};
