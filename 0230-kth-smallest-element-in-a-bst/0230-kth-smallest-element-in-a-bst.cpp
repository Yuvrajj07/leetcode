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
//  int inOrderTraversal(TreeNode* root,int k) {
//         if (root == nullptr ) {
//             return -1;
//         }
//         if (k==0){
//             return root->val;
//         }
//         inOrderTraversal(root->left,k--);
        
//         inOrderTraversal(root->right,k--);
//     }
//       int kthSmallest(TreeNode* root, int k) {
//     return inorderTraversal(root,k);
//     }
// };

class Solution {
public:
    int inOrderTraversal(TreeNode* root, int& k) {
        if (root == nullptr) {
            return -1;
        }
        int leftResult = inOrderTraversal(root->left, k);
        if (k == 0) {
            return leftResult;
        }
        k--;
        if (k == 0) {
            return root->val;
        }
        return inOrderTraversal(root->right, k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return inOrderTraversal(root, k);
    }
};
