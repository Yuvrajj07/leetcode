class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>v(n,-1);
        for (int i =0;i<n;i++){
            if (v[i]==-1){
                queue<int>q;
                q.push(i);
                v[i]=0;
                while (!q.empty()){
                    int node= q.front();
                    q.pop();
                    for (auto it :graph[node]){
                        if (v[it]==-1){
                            v[it]=1-v[node];
                            q.push(it);
                        }
                        else if (v[node]==v[it]){
                            return false;
                        }

                    }
                }
            }
        }
        return true;
    }
};
                    