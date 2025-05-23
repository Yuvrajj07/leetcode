class Solution {
public:
    void solve(int node ,vector<vector<int>>&v,vector<int>&vis){
        vis[node]=1;
        for (int i=0;i<v[node].size();i++){
            if (!vis[v[node][i]]){
                solve(v[node][i],v,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& adj) {
        vector<vector<int>>v;
        for (int i=0;i<adj.size();i++){
            vector<int>temp;
            for (int j=0;j<adj[i].size();j++){
                if (adj[i][j]==1 && i!=j)
                temp.push_back(j);
            }
            v.push_back(temp);
        }
    int ans=0;
    vector<int>vis(v.size(),0);
    for (int i =0;i<adj.size();i++){
        if (!vis[i]){
            ans++;
            solve(i,v,vis);
        }
    }    
    return ans;
    }
};