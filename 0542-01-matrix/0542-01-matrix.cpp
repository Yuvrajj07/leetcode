class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        vector<vector<int>>ans(n, vector<int>(m, 0));

        queue<pair<pair<int, int>, int>>q;

        for(int i = 0; i<n; i++){
            for(int j = 0; j < m ; j++){
                if(mat[i][j] == 0){
                    vis[i][j] = 1;
                    q.push({{i, j}, 0});
                }
            }
        }

vector<int>drow = {-1, 0, 1, 0};
vector<int>dcol = {0, 1, 0, -1};

        while(!q.empty()){

            int r = q.front().first.first;
            int c = q.front().first.second;
            int p = q.front().second;

            q.pop();

            for(int i = 0; i < 4; i++){
                int row = r + drow[i];
                int col = c + dcol[i];

                if(row >= 0 && row <n && col >= 0 && col < m){
                    if(vis[row][col] == 0){
                        q.push({{row, col}, p+1});
                        vis[row][col] = 1;
                        ans[row][col] = p+1;
                    }
                }
            }
        }

    return ans;

    }
};






// ................................DP TLE APPROACH.........................

// class Solution {
// public:
//     int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat,vector<vector<bool>> &vis){
//         if (i<0 || i>=mat.size() || j<0 || j>=mat[0].size()){
//             return  1e9;
//         }
//         if (mat[i][j]==0) return dp[i][j]= 0;
//         if (dp[i][j]!=-1) return dp[i][j];
//         if (vis[i][j]) return 1e9;// it means that results are not calcluated , it is under process for this
//                                   // value of i and j and it may lead to infinite recursion 
//         vis[i][j]=true;// avoiding infinite recursion . 
//         int up=1+solve(i-1,j,dp,mat,vis);
//         int down=1+solve(i+1,j,dp,mat,vis);
//         int left=1+solve(i,j-1,dp,mat,vis);
//         int right=1+solve(i,j+1,dp,mat,vis);
//         vis[i][j]=false;
//         return dp[i][j]=min({up,down,left,right});
//     }
//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//      int n= mat.size(),m=mat[0].size();
//      vector<vector<int>>dp(n,vector<int>(m,-1));
//      vector<vector<bool>> vis(n, vector<bool>(m, false));
//      vector<vector<int>>ans(n,vector<int>(m,0));
//      for (int i =0;i<n;i++){
//         for (int j=0;j<m;j++){
//             ans[i][j]=solve (i,j,dp,mat,vis);
//         }
//      }
//      return ans;   
//     }
// };


// class Solution {
// public:
//     void dfs(int i, int j, int dist, vector<vector<int>>& dp, const vector<vector<int>>& mat) {
//         int n = mat.size(), m = mat[0].size();
//         if (i < 0 || i >= n || j < 0 || j >= m) return;
//         if (dist >= dp[i][j]) return;   // no improvement, stop
//         dp[i][j] = dist;
//         dfs(i - 1, j, dist + 1, dp, mat);
//         dfs(i + 1, j, dist + 1, dp, mat);
//         dfs(i, j - 1, dist + 1, dp, mat);
//         dfs(i, j + 1, dist + 1, dp, mat);
//     }

//     vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//         int n = mat.size();
//         if (n == 0) return {};
//         int m = mat[0].size();
//         const int INF = INT_MAX / 2;
//         vector<vector<int>> dp(n, vector<int>(m, INF));

//         // Start a DFS from every zero cell
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (mat[i][j] == 0) {
//                     dfs(i, j, 0, dp, mat);
//                 }
//             }
//         }
//         return dp;
//     }
// };


