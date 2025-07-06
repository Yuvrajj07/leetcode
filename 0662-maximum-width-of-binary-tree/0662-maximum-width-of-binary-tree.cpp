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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth = 0;
        while (!q.empty()) {
            int size = q.size();
            unsigned long long startIdx = q.front().second; // first node index of current level
            unsigned long long endIdx = q.back().second;    // last node index of current level
            maxWidth = max(maxWidth, (int)(endIdx - startIdx + 1));
            for (int i = 0; i < size; ++i) {
                auto [node, idx] = q.front(); q.pop();
                idx -= startIdx; // normalize to prevent overflow
                if (node->left)  q.push({node->left, idx * 2});
                if (node->right) q.push({node->right, idx * 2 + 1});
            }
        }

        return maxWidth;
    }
};





// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
//        queue<TreeNode*>q;
//        q.push(root);
//        int ans=-1;
//        while (!q.empty()){
//             int z=q.size();
//             vector<TreeNode*>v;
//             for (int i =0;i<z;i++){
//             TreeNode *p=q.front();
//             q.pop();
//             v.push_back(p);
//             if (p->left && p->right) {
//                 q.push(p->left);
//                 q.push(p->right);
//             }
//             else if (p->left || p->right){
//                 if (p->left){
//                     q.push(p->left);
//                     q.push(NULL);
//                 }
//                 else {
//                     q.push(NULL);
//                     q.push(p->right);
//                 }
//             }
//             else {
//                 q.push(NULL);
//                 q.push(NULL);
//             }
//             }
//             int s=-1,e=-1;
//             for (int i=0;i<z;i++){
//                 if (v[i]!=NULL){
//                     s=i;
//                     break;
//                 }
//             }
//             for (int i=z-1;i>=0;i--){
//                 if (v[i]!=NULL){
//                     e=i;
//                     break;
//                 }
//             }
//             if (e!=-1 && s!=-1){
//                 ans =max(ans,abs(s-e));
//             }
            

//        }
//        return ans; 
//     }
// };