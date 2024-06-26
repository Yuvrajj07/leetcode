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
    int solve (TreeNode *root,int &ans){
        if (root==NULL) return 0;
        int l= solve(root->left,ans);
        int r= solve(root->right,ans);
        ans+= abs(l)+abs(r);
        return (l+r+root->val)-1;
    }
    int distributeCoins(TreeNode* root) {
        int moves=0;
        int a=solve(root,moves);
        return moves;
    }
};