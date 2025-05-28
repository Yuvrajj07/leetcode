// .........................COPIED ............................

class Solution {
public:
    // DFS to count reachable nodes within distance k
    int dfs(int node, int parent, const vector<vector<int>>& children, int k) {
        if (k < 0) return 0;

        int res = 1; // count self
        for (int child : children[node]) {
            if (child == parent) continue;
            res += dfs(child, node, children, k - 1);
        }
        return res;
    }

    // Build adjacency list and calculate targets for each node
    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> children(n);
        for (const auto& edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = dfs(i, -1, children, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        // Targets within Tree 1 using k distance
        vector<int> count1 = build(edges1, k);

        // Targets within Tree 2 using (k - 1) distance (one edge will be added)
        vector<int> count2 = build(edges2, k - 1);

        int maxCount2 = *max_element(count2.begin(), count2.end());

        // For each node in Tree 1, best case = targets in Tree 1 + max in Tree 2
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = count1[i] + maxCount2;
        }
        return res;
    }
};
