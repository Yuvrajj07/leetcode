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
/* ......................0(1)...............
 TO SOLVE THIS IN O(1)  SPACE  WE NEED TO FIND THE MID OF THE LIST REVERSE THE ELEMENTS AFTER THE MID 
 PLACE ONE POINTER TO THE MID POSITION AND ONE AT THE BEGINING OF THE LIST AND NOW START COMPARING ELEMENTS AT  OTH THE INDEXES .
 IF ANY ELEMENT IS DIFFERENT(NOT SAME )THEN THAT LIST IS NOT PALLINDROME ..
*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int>v;
        ListNode *p=head;
        while (p!=NULL){
            v.push_back(p->val);
            p=p->next;
        }
        int i =0,j=v.size()-1;
        while (i<j){
            if (v[i]!=v[j]) return false;
            i++;
            j--;
        }
        return true;
    }
};