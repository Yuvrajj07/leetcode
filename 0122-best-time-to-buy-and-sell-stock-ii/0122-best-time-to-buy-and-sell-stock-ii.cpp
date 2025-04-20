class Solution {
public:
    int solve(int idx, int canBuy, vector<int>& prices, int n, vector<vector<int>>& dp) {
        if (idx == n) return 0;
        if (dp[canBuy][idx] != -1) return dp[canBuy][idx];

        int profit = 0;
        if (canBuy) {
            // Choose to buy or skip
            profit = max(-prices[idx] + solve(idx + 1, 0, prices, n, dp),
                         solve(idx + 1, 1, prices, n, dp));
        } else {
            // Choose to sell or skip
            profit = max(prices[idx] + solve(idx + 1, 1, prices, n, dp),
                         solve(idx + 1, 0, prices, n, dp));
        }

        return dp[canBuy][idx] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(2, vector<int>(n, -1));  // Only 2 states: canBuy = 0 or 1
        return solve(0, 1, prices, n, dp);  // Start from index 0 and state = canBuy (1)
    }
};


// class Solution {
// public:
//     int solve (int idx,int buy,vector<int>v,int n,vector<vector<int>>&dp){
//         if(idx==n) {
//             return 0;
//         }
//         if (dp[buy][idx]!=-1) return dp[buy][idx];
//         int profit=0;
//         if (buy){
//                  return dp[buy][idx]=max(-v[idx]+solve(idx+1,0,v,n,dp),0+solve(idx+1,1,v,n,dp));
//         }
//         else {
//              return dp[buy][idx] =max(v[idx]+solve(idx+1,1,v,n,dp),0+solve(idx+1,0,v,n,dp));
//         }
//         return  dp[buy][idx];
//     }
//     int maxProfit(vector<int>& v) {
//         int n=v.size();  
//         vector<vector<int>>dp(2,vector<int>(n,-1));
//          return solve (0,1,v,n,dp);
//     }
// };