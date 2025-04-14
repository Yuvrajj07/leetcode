class Solution {
public:
    int solve(int n1,int n2,string s1,string s2,vector<vector<int>>&dp){
        if (n1<=0){
            return n2;
        }
        if (n2<=0){
            return n1;
        }
        if (dp[n1][n2]!=-1) return dp[n1][n2];
        if (s1[n1-1]==s2[n2-1]) return dp[n1][n2]=solve (n1-1,n2-1,s1,s2,dp);
        int insert=1+solve(n1,n2-1,s1,s2,dp);
        int deletee=1+solve(n1-1,n2,s1,s2,dp);
        int replace=1+solve(n1-1,n2-1,s1,s2,dp);
        return dp[n1][n2]=min(insert,min(deletee,replace));
   } 
    int minDistance(string word1, string word2) {
        int n1=word1.length(),n2=word2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        return solve(n1,n2,word1,word2,dp);
    }
};