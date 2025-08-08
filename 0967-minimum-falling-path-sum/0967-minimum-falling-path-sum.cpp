class Solution {
public:
    int solve (int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
        int m=mat.size();
        int n=mat[0].size();
        if (j <0 || j >= mat[0].size()) {
            return 10005;
        }
        if (i==m-1){
            return mat[m-1][j];
        }
        if (dp[i][j]!=-10040) return dp[i][j];
        int down =INT_MAX,rd=INT_MAX,ld=INT_MAX;
         down=mat[i][j]+solve(i+1,j,mat,dp);
         rd=mat[i][j]+solve(i+1,j+1,mat,dp);
         ld=mat[i][j]+solve(i+1,j-1,mat,dp);
        return  dp[i][j]=min(down,min(ld,rd));      
    }
    int minFallingPathSum(vector<vector<int>>&v) {
        int m = v.size();
        int n = v[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -10040));
        int ans=10005;
        for (int k =0;k<n;k++){
            ans= min (ans,solve(0,k,v,dp));
        }
        return ans;
    }
};