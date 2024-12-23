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
    int minSwapsToSort(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int, int>> arrPos(n);
        for (int i = 0; i < n; i++) {
            arrPos[i] = {arr[i], i};
        }
        sort(arrPos.begin(), arrPos.end());
        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || arrPos[i].second == i) {
                continue;
            }
            int cycle_size = 0;
            int x = i;
            while (!visited[x]) {
                visited[x] = true;
                x = arrPos[x].second; // Move to the next index in the cycle
                cycle_size++;
            }
            swaps += (cycle_size - 1);
        }
        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        int ans = 0;
        q.push(root);
        while (!q.empty()) {
            int z = q.size();
            vector<int> v;
            for (int i = 0; i < z; i++) {
                TreeNode* p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left != NULL) q.push(p->left);
                if (p->right != NULL) q.push(p->right);
            }
            ans += minSwapsToSort(v);
        }
        return ans;
    }
};


// class Solution {
// public:
// int minSwapsToSort(vector<int>& arr) {
//     int n = arr.size();
//     vector<pair<int, int>> arrPos(n);
//     for (int i = 0; i < n; i++) {
//         arrPos[i] = {arr[i], i};
//     }
//     sort(arrPos.begin(), arrPos.end());
//     vector<bool> visited(n, false);
//     int swaps = 0;

//     for (int i = 0; i < n; i++) {
//         if (visited[i] || arrPos[i].second == i) {
//             continue;
//         }
//         int cycle_size = 0;
//         int x = i;
//         while (!visited[x]) {
//             visited[x] = true;
//             x = arrPos[x].second; // Move to the next index in the cycle
//             cycle_size++;
//         }
//         swaps += (cycle_size - 1);
//     }
//     return swaps;
// }
//     int minimumOperations(TreeNode* root) {
//         queue<TreeNode*>q;
//         int ans=0;
//         q.push(root);
//         while (!q.empty()){
//             int z= q.size();
//             vector<int>v;
//             for (int  i =0;i<z;i++){
//                 TreeNode *p=q.front();
//                 q.pop();;
//                 v.push_back(p->val);
//                 if (p->right!=NULL)
//                 q.push(p->right);
                
//                 if (p->left!=NULL)
//                 q.push(p->left);
//             }
            
//             ans+=minSwapsToSort(v);

//         }
//         return ans;
//     }
// };