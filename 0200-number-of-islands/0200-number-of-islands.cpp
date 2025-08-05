class Solution {
public:
void bfs(int i ,int j,vector<vector<int>>&vis,vector<vector<char>>&c){
            int n= c.size(),m=c[0].size();
            if (i<0 || i>=n || j>=m || j<0 || c[i][j]!='1' || vis[i][j]==1){
                return ;
            }
            vis[i][j]=1;
                int rows[4]={1,0,0,-1};
                int cols[4]={0,1,-1,0};
                for (int k=0;k<4;k++){
                    int nrow=i+rows[k];
                    int ncol=j+cols[k];
                        bfs(nrow,ncol,vis,c);
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