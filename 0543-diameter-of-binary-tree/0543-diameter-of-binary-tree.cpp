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
// class Solution {
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//         int  dia =height(root);
//         return dia;
//     }
//     int height(TreeNode *root){
//         if (root==NULL)return 0;
//         int lh = diameterOfBinaryTree(root->left);
//         int rh = diameterOfBinaryTree(root->right);
//          int mx= max(mx,lh+rh);
//         return mx+1;
//     }
// };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia=0;
         height(root,dia);
        return dia;
    }
    int height(TreeNode *root,int &dia) {
        if (root == NULL) return 0;   
        int lh = height(root->left,dia);
        int rh = height(root->right,dia);
        dia = max(lh + rh,dia); // Update mx properly
        return max(lh,rh)+1;
    }
};
