class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        vector<vector<int>> dp(r, vector<int>(c, 0));

        // Initialize the base case (starting position)
        dp[0][0] = grid[0][0];

        // Fill the first row (only one way to reach these cells)
        for (int j = 1; j < c; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill the first column (only one way to reach these cells)
        for (int i = 1; i < r; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the rest of the DP table
        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[r - 1][c - 1]; // The last cell contains the minimum path sum
    }
};







// class Solution {
// public:

//     int solve(vector<vector<int>>v , int r, int c,vector<vector<int>>&dp){
//         if (r==0 && c==0) {
//             return v[0][0];
//         }
//         if (r<0 || c<0) return INT_MAX;
//         if (dp[r][c]!=-1) return dp[r][c];

//          dp[r][c]= v[r][c]+min({solve(v,r-1,c,dp),solve(v,r,c-1,dp)});
//          return dp[r][c];
//     }
//     int minPathSum(vector<vector<int>>& grid) {
//         int ans=0;
//         int r=grid.size(),c=grid[0].size();
//         vector<vector<int>>dp(r,vector<int>(c,-1));

//         return solve(grid,r-1,c-1,dp); 
  
//     }
// };
