class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;  // Freeing the memory allocated for dummyHead
        return result;
    }
};








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
//     ListNode * reverse(ListNode* head){
//         ListNode *curr=head,*forw=NULL,*prev=NULL;
//         while (curr!=NULL){
//             forw=curr->next;
//             curr->next=prev;
//             prev=curr;
//             curr=forw;
//         }
//         return prev;
//     }


// void appendNode(ListNode*& head, ListNode*& tail, int value) {
//         ListNode* newNode = new ListNode(value); // Create a new node
//         if (head == nullptr) {
//             head = newNode; 
//             tail = newNode; 
//         } else {
//             tail->next = newNode; 
//             tail = newNode;       
//         }
//     }

//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         // Reverse the input lists
//         l1 = reverse(l1);
//         l2 = reverse(l2);

//         ListNode* ans = nullptr;  // Result list
//         ListNode* tail = nullptr; // Tail pointer for appending
//         int carry = 0;

//         // Add the two lists
//         while (l1 != nullptr || l2 != nullptr || carry != 0) {
//             int z1 = (l1 != nullptr) ? l1->val : 0;
//             int z2 = (l2 != nullptr) ? l2->val : 0;
//             int total = z1 + z2 + carry;

//             int push = total % 10;  // Get the current digit
//             carry = total / 10;     // Update carry

//             appendNode(ans, tail, push);  // Append to the result list

//             // Move to the next nodes
//             if (l1 != nullptr) l1 = l1->next;
//             if (l2 != nullptr) l2 = l2->next;
//         }

//         // Reverse the result list to restore the correct order
        

//         return ans;
//     }


//     // ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//     //     ListNode* ans=nullptr;
//     //     ListNode* tail=nullptr;
        
//     //     reverse(l1);
//     //     reverse(l2);
//     //     int carry=0;
//     //     while (l1!=NULL  &&  l2!=NULL){
//     //         int z1= l1->val;
//     //         int z2= l2->val;
//     //         int total=(z1+z2+carry);
//     //         int push=total%10;
//     //         appendNode(ans,tail,push);
//     //         carry= total/10;
//     //     }
//     // reverse(ans);
//     //     return ans;      
//     // }
// };