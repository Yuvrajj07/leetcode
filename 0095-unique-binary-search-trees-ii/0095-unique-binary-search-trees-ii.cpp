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
    vector<TreeNode*> build(int start, int end) {
        vector<TreeNode*> res;
        
        if (start > end) {  // no numbers left -> empty tree
            res.push_back(nullptr);
            return res;
        }
        for (int rootVal = start; rootVal <= end; rootVal++) {
            vector<TreeNode*> leftTrees = build(start, rootVal - 1);
            vector<TreeNode*> rightTrees = build(rootVal + 1, end);

            for (TreeNode* L : leftTrees) {
                for (TreeNode* R : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal);
                    root->left = L;
                    root->right = R;
                    res.push_back(root);
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return build(1, n);
    }
};


// Divide the problem:

// Pick each number i in [start, end] as the root.

// Then the numbers < i must go in the left subtree, and numbers > i must go in the right subtree.

// Conquer recursively:

// Recursively build all possible left subtrees from [start, i-1].

// Recursively build all possible right subtrees from [i+1, end].

// Combine results:

// For each left subtree and each right subtree, attach them to the root i and push that tree into the answer.
