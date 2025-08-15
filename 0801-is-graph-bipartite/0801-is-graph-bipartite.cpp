class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
          int V = graph.size();
        vector<int> color(V, -1); // -1 means uncolored

        for (int start = 0; start < V; start++) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0; // start with color 0

                while (!q.empty()) {
                    int node = q.front();
                    q.pop();

                    for (int neigh : graph[node]) {
                        if (color[neigh] == -1) {
                            color[neigh] = 1 - color[node]; // alternate color
                            q.push(neigh);
                        }
                        else if (color[neigh] == color[node]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};