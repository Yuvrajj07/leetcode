/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *curr=root,*left=NULL;
        while (curr!=NULL){
            if (curr->left){
                left=curr->left;
                TreeNode *t1=left;
            while (t1->right!=NULL) t1=t1->right;
            t1->right=curr->right;
            curr->right=left;
            curr->left=NULL;
            }
            curr=curr->right;
        }
    }
};