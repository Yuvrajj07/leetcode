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
    vector<int> largestValues(TreeNode* root) {
        vector<int>ans;
        if (root == nullptr) return ans; 
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()){
            int mn=INT_MIN;
            int x= q.size();
            for (int i =0;i<x;i++){
                TreeNode *p=q.front();
                q.pop();
                int z=p->val;
                mn=max(mn,z);
                if (p->right!=NULL) q.push(p->right);
                if (p->left!=NULL) q.push(p->left);
                   
            }
            ans.push_back(mn);
        }
        return ans;
        
    }
};
