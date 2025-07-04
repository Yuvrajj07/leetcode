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
    int ans=0;
    int dfs(TreeNode *root){
        if (!root) return 1;
        int left= dfs(root->left);
        int right= dfs(root->right);
        if (left==0  ||  right==0){
            ans++;
            return 2;
        }
        else if (left==2 || right==2){
            return 1;
        }
        else {
            return 0;
        }
    }    
    int minCameraCover(TreeNode* root) {
        if (dfs(root)==0) ans++;
        return ans;
    }
};

/*
class Solution {
public:
    #define NO_CAMERA       0
    #define HAS_CAMERA      2
    #define NOT_NEEDED      1
    int ans = 0;
    int dfs(TreeNode *root) {
        if (!root) return NOT_NEEDED;
        int l = dfs(root->left);
        int r = dfs(root->right);
        if (l == NO_CAMERA || r == NO_CAMERA) {
            ans++;
            return HAS_CAMERA;
        } else if (l == HAS_CAMERA || r == HAS_CAMERA) {
            return NOT_NEEDED;
        } else {
            return NO_CAMERA;
        }
    }
    */