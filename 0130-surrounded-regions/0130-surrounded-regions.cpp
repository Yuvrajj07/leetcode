class Solution {
public:
    void dfs(vector<vector<char>>&v,vector<vector<int>>&vis,int i ,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while (!q.empty()){
            pair<int,int>p=q.front();
            q.pop();
            int r=p.first,c=p.second;
            vis[r][c]=1;
            int nrow[4]={0,1,-1,0};
            int ncol[4]={-1,0,0,1};
            for (int i =0;i<4;i++){
                int neighr=r+nrow[i];
                int neighc=c+ncol[i];
                if (neighr>=0 && neighr<v.size()  && neighc>=0 && neighc<v[0].size() && v[neighr][neighc] == 'O' && !vis[neighr][neighc]){
                    vis[neighr][neighc]=1;
                    q.push({neighr,neighc});

                }

            }
        }
    }    void solve(vector<vector<char>>& v) {
        int m=v.size(),n=v[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        for (int i =0;i<m;i++){
            if(v[i][0]=='O') dfs(v,vis,i,0);
            if(v[i][n-1]=='O') dfs(v,vis,i,n-1);
        }   
        for (int i =0;i<n;i++){
            if(v[0][i]=='O') dfs(v,vis,0,i);
            if(v[m-1][i]=='O') dfs(v,vis,m-1,i);
        }   
        for(int i =0;i<m;i++){
            for (int j=0;j<n;j++){
                if (vis[i][j]!=1) {
                    v[i][j]='X';
                }
            }
        }        
    }
};