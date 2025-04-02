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
    int minDepth(TreeNode* root) {
        if (!root)
        return 0;

    std::queue<TreeNode*> q;
    q.push(root);

    int level = 1; // Initialize the level to 1

    while (!q.empty()) {
        int size = q.size();

        for (int i = 0; i < size; ++i) {
            TreeNode* current = q.front();
            q.pop();

            if (current->left || current->right) {
                if (current->left)
                    q.push(current->left);

                if (current->right)
                    q.push(current->right);
            } 
            else {
                // If both left and right children are null, return the current level
                return level;
            }
        }

        // Move to the next level
        ++level;
    }

    return -1;
}

        
    
};