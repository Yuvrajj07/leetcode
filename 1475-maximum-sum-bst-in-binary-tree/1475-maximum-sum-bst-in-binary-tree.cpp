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
    //  solve (TreeNode *root,vector<dt> &node){
    //     solve(root->left,node);
    //     solve(root->right,node);
        
    //     if (root->left==NULL && root->right ==NULL ) {
    //         dt n1;
    //         n1->left_min=INT_MAX;
    //         n1->right_max=INT_MIN;
    //         n1->curr_sum=root->val;
    //         dt.push_back(n1);
    //     } 


    int ans=0;
    vector<int> solve(TreeNode *root){
        if (root==NULL){
            return {INT_MAX,INT_MIN,0};
        }
        vector<int>left=solve(root->left);
        vector<int>right=solve(root->right);
        if (root->val>left[1] && root->val<right[0]){
            int sum=root->val+left[2]+right[2];
            ans=max(ans,sum);
            return {min(left[0],root->val),max(root->val,right[1]),sum};
        }
        return {INT_MIN,INT_MAX,0};
    }
    int maxSumBST(TreeNode* root) {
       solve(root);
        return ans;
    }
};