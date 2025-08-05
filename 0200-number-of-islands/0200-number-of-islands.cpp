class Solution {
public:
void bfs(int i ,int j,vector<vector<int>>&vis,vector<vector<char>>&c){
            int n= c.size(),m=c[0].size();
            vis[i][j]=1;
            queue<pair<int,int>>q;
            q.push({i,j});
            while (!q.empty()){
                int rows[4]={1,0,0,-1};
                int cols[4]={0,1,-1,0};
                pair<int,int>p=q.front();
                q.pop();
                for (int i=0;i<4;i++){
                    int nrow=p.first+rows[i];
                    int ncol=p.second+cols[i];
                    if (nrow>=0 && nrow<n && ncol<m && ncol>=0 && c[nrow][ncol]=='1' && vis[nrow][ncol]!=1){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
}
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for (int i =0;i<n;i++){
            for (int j=0;j<m;j++){
                if (grid[i][j]=='1' && !vis[i][j]){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};