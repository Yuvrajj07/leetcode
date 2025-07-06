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
    vector<vector<int>>ans;
    void solve(TreeNode *root,int t,vector<int>&v){
        if (root==NULL) return ;
        v.push_back(root->val);
        t-=root->val;
        if (root->left==NULL && root->right ==NULL && t==0){
            ans.push_back(v);
        }
        solve(root->left,t,v);
        solve(root->right,t,v);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        solve(root,targetSum,temp);
        return ans;
    }
};