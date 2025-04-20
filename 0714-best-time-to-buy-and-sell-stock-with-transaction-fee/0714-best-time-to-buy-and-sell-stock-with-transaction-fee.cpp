class Solution {
public:
    int solve(int idx,int n,int buy,vector<int>&v,vector<vector<int>>&dp,int fee){
            if (idx>=n) return 0;
            if (dp[idx][buy]!=-1)  return dp[idx][buy];
            if (buy){
                dp[idx][buy]=max(-v[idx]+solve(idx+1,n,0,v,dp,fee),solve(idx+1,n,1,v,dp,fee));
            }
            else {
                dp[idx][buy]=max(v[idx]-fee+solve(idx+1,n,1,v,dp,fee),solve(idx+1,n,0,v,dp,fee));

            }
            return dp[idx][buy];

    }
    int maxProfit(vector<int>& v, int fee) {
        int n=v.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,n,1,v,dp,fee);
    }
};

