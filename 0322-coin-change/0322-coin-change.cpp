// class Solution {
// public:
//     int solve(int i,int amount ,int n,vector<int>v,vector<vector<int>>&dp){
//       if (i==n) {
//         return (amount==0)?0:1e9;
//       }
//       if (dp[i][amount]!=-1) return dp[i][amount];
//       int include =1e9;
//       if (v[i]<=amount){
//         include =1+solve(i,amount-v[i],n,v,dp);
//       }
//       int exclude = solve(i+1,amount,n,v,dp);
//       return dp[i][amount]=min(include ,exclude );
//     }
//     int coinChange(vector<int>&v, int amount) {
//         if (v.size()==1 && v[0]==1 ) return amount;
//         int n=v.size();
//         vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
//         int ans=solve(0,amount,n,v,dp);
//          return  (ans>=1e9) ? -1 :ans;
        
//     }
// };


class Solution {
public:
    int solve(int i, int amount, int n, vector<int>& v, vector<vector<int>>& dp) {
        if (i == n) {
            return (amount == 0) ? 0 : 1e9; // large number instead of INT_MAX to avoid overflow
        }

        if (dp[i][amount] != -1) return dp[i][amount];

        int include = 1e9;
        if (v[i] <= amount) {
            include = 1 + solve(i, amount - v[i], n, v, dp); // reuse coin
        }

        int exclude = solve(i + 1, amount, n, v, dp); // skip coin

        return dp[i][amount] = min(include, exclude);
    }

    int coinChange(vector<int>& v, int amount) {
        int n = v.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        int ans = solve(0, amount, n, v, dp);
        return (ans >= 1e9) ? -1 : ans;
    }
};
