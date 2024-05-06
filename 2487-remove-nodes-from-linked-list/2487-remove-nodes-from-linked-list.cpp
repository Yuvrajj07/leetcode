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
// class Solution {
// public:
//     ListNode* removeNodes(ListNode* head) {
//            if (head == nullptr) // Check if head is nullptr
//         return nullptr;

//     ListNode* p = head;
//     stack<ListNode*> st;
//     while (p != nullptr) {
//         st.push(p);
//         p = p->next;
//     }
//         p= st.top();
//         st.pop();
//         int mx=p->val;
//         ListNode *ans= new ListNode(mx);
//         while (!st.empty()){
//             p=st.top();
//             st.pop();
//             if (p->val>mx){
//              continue;
//             }
//             else {
//                 ListNode *NewNode=new ListNode(p->val);
//                 NewNode->next=ans;
//                 ans=NewNode;
//                 mx=p->val;
//             }
            
//         }
//         return ans;
        
//     }
// };

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        stack<ListNode*> stack;
        ListNode* current = head;

        // Add nodes to the stack
        while (current != nullptr) {
            stack.push(current);
            current = current->next;
        }

        current = stack.top();
        stack.pop();
        int maximum = current->val;
        ListNode* resultList = new ListNode(maximum);

        // Remove nodes from the stack and add to result
        while (!stack.empty()) {
            current = stack.top();
            stack.pop();
            // Current should not be added to the result
            if (current->val < maximum) {
                continue;
            }
            // Add new node with current's value to front of the result
            else {
                ListNode* newNode = new ListNode(current->val);
                newNode->next = resultList;
                resultList = newNode;
                maximum = current->val;
            }
        }

        return resultList;
    }
};