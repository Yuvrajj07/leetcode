class Solution {
public:
    int solve(int i ,int n,int x,vector<vector<int>>&dp){
        int p = (int)pow(i, x);
        if (p==n) return true;
        if (p>n) return 0;
        if (dp[i][n]!=-1) return dp[i][n];
        int take =solve(i+1,n-p,x,dp) %1000000007;
        int ntake =solve(i+1,n,x,dp)%1000000007;
        return dp[i][n]= (take+ntake)%1000000007;
    }
    int numberOfWays(int n, int x) {     
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
     return solve(1,n,x,dp);   
    }
};