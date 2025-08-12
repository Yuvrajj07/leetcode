class Solution {
public:
    int solve (int s,int e,string &s1,vector<vector<int>>&dp){
        if (s>e) return 0;
        if (dp[s][e]!=-1) return dp[s][e];
        if (s1[s]==s1[e]){
            if (s==e) return 1+solve(s+1,e-1,s1,dp);
            else return 2+solve(s+1,e-1,s1,dp);
        }
        return dp[s][e]=max(solve(s+1,e,s1,dp),solve(s,e-1,s1,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n= s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,dp);
        
    }
};