// class Solution {
// public:
//     int solve(int s,int e,string s1,vector<vector<int>>&dp){
//         if (e<s) return 0;
//         if (dp[s][e]!=-1) return dp[s][e];
//         if (s1[s]==s1[e]){
//             if (s==e)  return 1+solve(s+1,e-1,s1,dp);
//             else return 2+solve(s+1,e-1,s1,dp);
//         }
//         else  return dp[s][e]= max(solve(s+1,e,s1,dp),solve(s,e-1,s1,dp));    
//         return dp[s][e];        
//     }
//     int longestPalindromeSubseq(string s) {
//         int n= s.length();
//         vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
//          return solve(0,n-1,s,dp);
//     }
// };

class Solution {
public:
    int solve(int s, int e, const string& s1, vector<vector<int>>& dp) {
        if (e < s) return 0;  // Base case: invalid range
        if (s == e) return 1; // Base case: single character is a palindrome
        
        if (dp[s][e] != -1) return dp[s][e];

        if (s1[s] == s1[e]) {
            dp[s][e] = 2 + solve(s + 1, e - 1, s1, dp);
        }
         else {
            dp[s][e] = max(solve(s + 1, e, s1, dp), solve(s, e - 1, s1, dp));
        }
        return dp[s][e];
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(0, n - 1, s, dp);
    }
};
