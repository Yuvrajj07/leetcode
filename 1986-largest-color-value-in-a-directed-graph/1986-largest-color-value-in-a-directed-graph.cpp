
// LOGIC.....
// 1. Build the adjacency list for the graph.
// 2. Use DFS with memoization to compute max color counts for each node.
// 3. Use a dp[node][color] table to store results (memoization).
// 4. Use a recursion stack (inStack) to detect cycles.
// 5. During DFS:
//    - For each neighbor, get its dp and update current node’s dp.
//    - After processing neighbors, increment the count for current node’s color.
// 6. If a cycle is detected, return -1.
// 7. Else, return the maximum value among all dp[node][color].

class Solution {
public:
    vector<vector<int>> graph;
    vector<vector<int>> dp;
    vector<bool> visited;
    vector<bool> inStack;
    bool hasCycle = false;

    vector<int> dfs(int node, const string& colors) {
        if (hasCycle) return vector<int>(26, 0);

        if (visited[node]) return dp[node];  // Memoization

        visited[node] = true;
        inStack[node] = true;

        vector<int> count(26, 0);

        for (int neighbor : graph[node]) {
            if (inStack[neighbor]) {
                hasCycle = true;
                return vector<int>(26, 0);
            }

            vector<int> neighborCount = dfs(neighbor, colors);
            for (int c = 0; c < 26; ++c) {
                count[c] = max(count[c], neighborCount[c]);
            }
        }

        // Add current node's color
        count[colors[node] - 'a'] += 1;
        dp[node] = count;

        inStack[node] = false;
        return count;
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        graph.resize(n);
        dp.assign(n, vector<int>(26, 0));
        visited.assign(n, false);
        inStack.assign(n, false);

        // Build graph
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }

        int result = 0;

        for (int i = 0; i < n; ++i) {
            vector<int> counts = dfs(i, colors);
            if (hasCycle) return -1;
            result = max(result, *max_element(counts.begin(), counts.end()));
        }

        return result;
    }
};
