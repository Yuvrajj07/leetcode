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
    int ans=INT_MIN;
    int solve (TreeNode *root){
        if (root==NULL) return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        int mx2=root->val+left+right;
        int mx1=root->val+max(left,right);
        int mx0=root->val;
        ans=max(ans,max(mx1,max(mx2,mx0)));
        return max(mx0,mx1);   
        
    }
    int maxPathSum(TreeNode* root) {
         solve(root);
         return ans;

    }
};