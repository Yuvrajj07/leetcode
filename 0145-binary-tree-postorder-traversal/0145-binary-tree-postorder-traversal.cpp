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
     void postorder(TreeNode* root, vector<int> &v) {
        if (root == NULL) return;

        postorder(root->left, v);    // Traverse the left subtree
        postorder(root->right, v);   // Traverse the right subtree
        v.push_back(root->val);      // Visit the root node
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        TreeNode *p=root;
        postorder(root,v);
        return v;
    }
};