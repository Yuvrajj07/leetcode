

// class Solution {
// public:
//     int solve (int s,int e,string &s1,vector<vector<int>>&dp){
//         if (s>e) return 0;
//         if (dp[s][e]!=-1) return dp[s][e];
//         if (s1[s]==s1[e]){
//             if (s==e) return 1+solve(s+1,e-1,s1,dp);
//             else return 2+solve(s+1,e-1,s1,dp);
//         }
//         return dp[s][e]=max(solve(s+1,e,s1,dp),solve(s,e-1,s1,dp));
//     }
//     int longestPalindromeSubseq(string s) {
//         int n= s.length();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//         return solve(0,n-1,s,dp);
        
//     }
// };


//  ..........................TABULATION  - BOTTOM UP ............................
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for (int i=0;i<n;i++){
            dp[i][i]=1;
        }
        for (int i=n-1;i>=0;i--){
            for (int j = i + 1; j < n; j++) {
                if (s[i]==s[j]) {
                    dp[i][j]=2+dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        return dp[0][n-1];
    }
};

