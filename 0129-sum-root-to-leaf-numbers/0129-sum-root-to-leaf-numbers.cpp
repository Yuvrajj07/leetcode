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
    int solve(TreeNode *root,int num){
        num= num*10+root->val;
        if (root->left== NULL && root->right==NULL) return num;
        int result=0;
        if (root->left) result+=solve(root->left,num);
        if (root->right) result+=solve(root->right,num);
        return result;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};