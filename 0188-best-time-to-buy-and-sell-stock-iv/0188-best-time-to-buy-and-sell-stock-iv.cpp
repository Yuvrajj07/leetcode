class Solution {
public:
    int solve (int idx ,int buy,int cap ,vector<int>&v,int n,vector<vector<vector<int>>>&dp){
        if (idx==n) return 0;
        if (cap==0) return 0;
        if (dp[idx][buy][cap]!=-1)return dp[idx][buy][cap];
        int profit=0;
        if (buy){
            profit=max(-v[idx]+solve (idx+1,0,cap,v,n,dp),0+solve (idx+1,1,cap,v,n,dp));
        }
        else {
            profit =max(v[idx]+solve(idx+1,1,cap-1,v,n,dp),0+solve(idx+1,0,cap,v,n,dp));
        }
        return  dp[idx][buy][cap]=profit;
    }
    int maxProfit(int k , vector<int>& prices) {
        int n= prices.size();
      vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve (0,1,k,prices,n,dp);
    }
};