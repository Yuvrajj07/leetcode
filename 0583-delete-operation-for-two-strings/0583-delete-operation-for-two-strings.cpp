class Solution {
public:
    int solve(string s1,string s2,int n1,int n2,vector<vector<int>>&dp){
        if (n1==0 || n2==0)  return 0;// base condition 
        if (dp[n1][n2]!=-1) return dp[n1][n2];
        if (s1[n1-1]==s2[n2-1]) {
                return  dp[n1][n2]=1+solve(s1,s2,n1-1,n2-1,dp);
        }
        else  return dp[n1][n2]=max(solve(s1,s2,n1,n2-1,dp),solve(s1,s2,n1-1,n2,dp));
    }
    int minDistance(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        int z= solve(s1,s2,n1,n2,dp);
        return n1+n2-2*z;
    }
};