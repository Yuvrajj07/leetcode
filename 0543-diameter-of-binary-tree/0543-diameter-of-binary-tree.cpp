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
int ans;
int solve(TreeNode*root)
{
     if(root==NULL)
        return 0;
        int left=solve(root->left);
      
           int right =solve(root->right);
        ans=max(left+right,ans);
        return max(left,right)+1;

}
    int diameterOfBinaryTree(TreeNode* root) {
       
        ans=0;
        solve(root);
        return ans;

    }
};