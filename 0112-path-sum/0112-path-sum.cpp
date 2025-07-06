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
        bool ans=false;
        void solve(TreeNode* root,int t){
            if(root==nullptr){
                return;
            }
            
          t-=root->val;
        if(root->left==nullptr && root->right==nullptr && t==0){
                ans=true;
            }

          solve(root->left,t);
          solve(root->right,t);
        } 
    bool hasPathSum(TreeNode* root, int targetSum) {
         solve(root,targetSum);  
         if(ans){
            return true;
         }
         return false;
    }
};