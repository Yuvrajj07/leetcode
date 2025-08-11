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
    void graph(TreeNode *root,unordered_map<int,vector<int>>&m){
        if (root==NULL) return ;
        int curr=root->val;
        if (root->left){
            m[curr].push_back(root->left->val);
            m[root->left->val].push_back(curr);

        } 
        if (root->right){
          m[curr].push_back(root->right->val);
          m[root->right->val].push_back(curr);

        } 
        graph(root->left,m);
        graph(root->right,m);
    }
    int bfs(unordered_map<int,vector<int>>&m,int start){
        queue<int>q;
        unordered_map<int,int>vis;
        int ans=0;
        q.push(start);
        vis[start]=1;
        while (!q.empty()){
            int size=q.size();
            for (int i =0;i<size;i++){
                int node=q.front();
                q.pop();
                for (int i =0;i<m[node].size();i++){
                    int neighbor = m[node][i];
                    if (vis.find(neighbor) == vis.end()) {
                        vis[neighbor] = 1;
                        q.push(neighbor);
                    }                }
            }
            ans++;
        }
        return ans;

    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>m;
        graph(root,m);
        int z=bfs(m,start);
        return z-1;
    }
};