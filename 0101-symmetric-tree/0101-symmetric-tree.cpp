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
    bool isSymmetric(TreeNode* root) {
        if (root==NULL) return true;
        TreeNode *right= root->right;
        TreeNode *left= root->left;
        return chk(left,right);
    }
        bool chk ( TreeNode *left,  TreeNode *right){
            if (right==NULL && left==NULL){
                return true;
        }
            if (right==NULL || left==NULL){
                return false;
        }
            // return (left->val == right->val) &&  (right->right==left->left ) && (right->left == left ->right);
             return (left->val == right->val) && chk(left->left, right->right) && chk(left->right, right->left);
    }
};

    
