class Solution {
public:
    int lcs(string& s1, string& s2, int m, int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0) {
                    // One of the two strings is empty.
                    dp[i][j] = 0;
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    int minInsertions(string s) {
        int n = s.length();
        string sReverse = s;
        reverse(sReverse.begin(), sReverse.end());

        return n - lcs(s, sReverse, n, n);
    }
};

//......................MEMOZIATION .........................

// class Solution {
// public:
//     int solve(string s1,string s2,int n,int m,vector<vector<int>>&dp){
//         if (m==0 || n==0 )  return 0;
//         if (dp[m][n]!=-1) return dp[m][n];
//         if (s1[m-1]==s2[n-1]){
//             return dp[m][n]= 1+solve(s1,s2,n-1,m-1,dp);
//         } 
//         return dp[m][n]=max(solve(s1,s2,n-1,m,dp ), solve(s1,s2,n,m-1,dp));
      
//     }
//     int minInsertions(string s1) {
//         int n=s1.length();
//         string s2= s1;
//         reverse(s2.begin(),s2.end());
//         vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
//         return  n- solve(s1,s2,n,n,dp);
//     }
// };