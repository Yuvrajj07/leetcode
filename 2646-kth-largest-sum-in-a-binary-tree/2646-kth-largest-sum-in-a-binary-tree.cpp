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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*>q;
        multiset<long long >m;
        q.push(root);
        while (!q.empty()){
            int z=q.size();
            long long  a=0;
            for (int i =0;i<z;i++){
                TreeNode *p=q.front();
                a+=p->val;
                q.pop();
                if (p->left!=NULL) q.push(p->left);
                if (p->right!=NULL) q.push(p->right);
                
            }
            m.insert(a);
        }
        
        for (auto it:m){
            cout<<it<<" ";
        }k--;
        while (k-- && !m.empty()) {
            m.erase(prev(m.end()));  // Remove the largest element
        }
        if(m.size()<=0) return -1;
        return *m.rbegin();
       

    }
};