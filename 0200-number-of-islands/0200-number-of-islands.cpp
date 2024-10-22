class Solution {
    private: 
    void  bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>grid){
        vis[row][col]=1;
        int n= grid.size(),m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({row,col});
        while (!q.empty()){
            int row1= q.front().first;
            int col1= q.front().second;
            q.pop();
             int delRow[] = {-1, 0, 1, 0};
             int delCol[] = {0, -1, 0, 1};
              for (int i = 0; i < 4; i++) {  // Looping only for 4 directions
                int nrow = row1 + delRow[i];
                int ncol = col1 + delCol[i];
                // Check for valid cell and whether it's part of an island ('1') and not visited yet
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol]) {
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int row= grid.size();
        int col=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for (int r=0;r<row;r++){
            for (int c=0;c<col;c++){
                if (!vis[r][c] && grid[r][c]=='1'){
                    cnt++;
                    bfs(r,c,vis,grid);
                }
            }
        }
        return cnt;
    }
};