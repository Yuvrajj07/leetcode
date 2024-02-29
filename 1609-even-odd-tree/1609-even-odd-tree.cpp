#include <queue>
using namespace std;

class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0; // Initialize level
        
        while (!q.empty()) {
            int size = q.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            
            for (int i = 0; i < size; ++i) {
                TreeNode* p = q.front();
                q.pop();
                if ((level % 2 == 0 && (p->val % 2 == 0 || p->val <= prev)) ||
                    (level % 2 != 0 && (p->val % 2 != 0 || p->val >= prev))) {
                    return false;
                }
                prev = p->val;
                if (p->left) q.push(p->left);
                if (p->right) q.push(p->right);
            }
            ++level;
        }
        return true;
    }
};
