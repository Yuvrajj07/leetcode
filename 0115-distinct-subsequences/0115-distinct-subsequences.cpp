class Solution {
public: 
    int solve(int n1,int n2,string s1,string s2,vector<vector<int>>&dp,string ans){
        if (n2==0)  return 1;
        if (n1==0 ) return 0;
        if (dp[n1][n2]!=-1){
            return dp[n1][n2];
        }
        // if (ans==s1) return 1+solve(n1-1,n2-1,s1,s2,dp,ans);
         if  (s1[n1-1]==s2[n2-1]) {
            dp[n1][n2]=solve(n1-1,n2-1,s1,s2,dp,ans)+solve(n1-1,n2,s1,s2,dp,ans);
        }
        else  dp[n1][n2]=solve(n1-1,n2,s1,s2,dp,ans);
        return dp[n1][n2];
  }
    int numDistinct(string s1, string s2) {
        int n1=s1.length(),n2= s2.length();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,-1));
        string ans="";
        return solve(n1,n2,s1,s2,dp,ans);
    }
};