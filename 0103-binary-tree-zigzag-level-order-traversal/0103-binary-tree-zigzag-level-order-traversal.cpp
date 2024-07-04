#include <bits/stdc++.h>
using namespace std;
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool chk = true;
        
        while (!q.empty()) {
            int s = q.size();
            vector<int> z(s);
            
            for (int i = 0; i < s; ++i) {
                TreeNode* p = q.front();
                q.pop();
                int index = chk ? i : (s - 1 - i);
                z[index] = p->val;                
                if (p->left != nullptr) q.push(p->left);
                if (p->right != nullptr) q.push(p->right);
            }
            
            ans.push_back(z);
            chk = !chk;
        }
        
        return ans;
    }
};



// #include <vector>
// #include <queue>
// #include <algorithm> // for reverse function

// using namespace std;

// // Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

// class Solution {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
//         vector<vector<int>> ans;
//         if (root == nullptr) return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
//         bool chk = true;
        
//         while (!q.empty()) {
//             int s = q.size();
//             vector<int> z;
            
//             for (int i = 0; i < s; ++i) {
//                 TreeNode* p = q.front();
//                 q.pop();
                
//                 z.push_back(p->val);
                
//                 if (p->left != nullptr) q.push(p->left);
//                 if (p->right != nullptr) q.push(p->right);
//             }
            
//             // Reverse the current level's values if chk is false
//             if (!chk) {
//                 reverse(z.begin(), z.end());
//             }
            
//             ans.push_back(z);
//              chk = !chk;
//         }
        
//         return ans;
//     }
// };
