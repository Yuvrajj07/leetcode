/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        stack<Node*> st;

        while (curr != NULL) {
            // If there is a child
            if (curr->child != NULL) {
                // If there's a next node, push it to stack
                if (curr->next != NULL) {
                    st.push(curr->next);
                }
                // Link child as next
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = NULL;
            }
            // If no next and stack not empty, pop and connect
            if (curr->next == NULL && !st.empty()) {
                Node* ptr = st.top();
                st.pop();
                curr->next = ptr;
                if (ptr != NULL) {
                    ptr->prev = curr;
                }
            }
            curr = curr->next;
        }
        return head;
    }
};


// class Solution {
// public:
//     Node* flatten(Node* head) {
//         // Node *ans
//         Node *nw=new Node();
//         nw->val=-1;
//         if (head==NULL) return head;
//         Node *curr=head;
//         stack<Node*>st;
//         st.push(nw);
//         while (curr !=NULL ||  !st.empty() ){
//             if (curr->child==NULL) curr= curr->next;
//             else {
//                 while (curr->child){
//                     if (curr->child!=NULL){
//                         st.push(curr->next);
//                         Node *nx= curr->child;
//                         nx->prev=curr;
//                         curr->next=nx;
//                         curr->child=NULL;
//                         curr=curr->next;
//                         break;
//                     }
//                 }
//             }
//             if (curr->next ==NULL && !st.empty()  ){
//                 if (st.top()->val<0) break;
//                 Node *ptr=st.top();
//                 st.pop();
//                 curr->next=ptr;
//                 ptr->prev=curr;
//                 // curr=ptr;
//                 curr=curr->next;
//                 }
//             }
//             return head;
//         }
// };