class Solution {
public:
    int solve(int idx,int buy, int n,vector<int>&v,vector<vector<int>>&dp){
        if (idx >=n) return 0;
        if (dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        int profit =0;
        if (buy){
            profit=max(-v[idx]+solve(idx+1,0,n,v,dp),solve(idx+1,1,n,v,dp));

        }
        else {
            profit=max(v[idx]+solve(idx+2,1,n,v,dp),solve(idx+1,0,n,v,dp));
        }
        return dp[idx][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,n,prices,dp);
    }
};