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
    vector<int> largestValues(TreeNode* root) {
        vector<int> currentLevel1;   
         if (root == nullptr) return currentLevel1;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
                   vector<int> currentLevel;   
 
            int levelSize = q.size();  // Number of nodes at the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            int x=*max_element(currentLevel.begin(),currentLevel.end());
          currentLevel1.push_back(x);
        }

        return  currentLevel1;
    }
};