class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for (int i=0;i<m;i++){
            dp[i][0]=1;
        }
        for (int i=0;i<n;i++){
            dp[0][i]=1;
        }
        for (int i =1;i<m;i++){
            for (int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
        
    }
};


// ...................MEMOIZATION..............................
// class Solution {
// public:
//     int solve (int i,int j,int m,int n,vector<vector<int>>&dp){
//         if (i==m-1 && j==n-1) return 1;
//         if (dp[i][j]!=-1) return dp[i][j];
//         int right=0,down=0;
//         if (i<m-1){
//             down=solve(i+1,j,m,n,dp);
//         }
//         if (j<n-1){
//             right=solve(i,j+1,m,n,dp);
//         }
//         return dp[i][j]=right+down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>>dp(m,vector<int>(n,-1));
//         return solve (0,0,m,n,dp);
//     }
// };