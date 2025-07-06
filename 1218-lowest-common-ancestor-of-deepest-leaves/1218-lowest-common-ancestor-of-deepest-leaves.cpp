// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
class Solution {
public:
    // Helper function that returns {depth, LCA node}
    pair<int, TreeNode*> dfs(TreeNode* root) {
        if (!root) return {0, nullptr};

        auto left = dfs(root->left);
        auto right = dfs(root->right);

        // Case 1: Equal depth → this node is LCA
        if (left.first == right.first) {
            return {left.first + 1, root};
        }

        // Case 2: Left deeper
        if (left.first > right.first) {
            return {left.first + 1, left.second};
        }

        // Case 3: Right deeper
        return {right.first + 1, right.second};
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};



// class Solution {
// public:
//     TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
//     }
// };