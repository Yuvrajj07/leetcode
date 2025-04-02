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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;

        // Base case: If the root is null, return an empty vector
        if (root == nullptr) {
            return ans;
        }

        // Traverse the left subtree
        vector<int> leftSubtree = inorderTraversal(root->left);
        ans.insert(ans.end(), leftSubtree.begin(), leftSubtree.end());

        // Visit the current node
        ans.push_back(root->val);

        // Traverse the right subtree
        vector<int> rightSubtree = inorderTraversal(root->right);
        ans.insert(ans.end(), rightSubtree.begin(), rightSubtree.end());

        return ans;
    }
};