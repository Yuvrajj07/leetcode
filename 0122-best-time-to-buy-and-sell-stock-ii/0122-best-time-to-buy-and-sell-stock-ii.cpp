class Solution {
public:
    int solve (int idx,int buy,vector<int>&v,int n,vector<vector<int>>&dp){
        if(idx==n) {
            return 0;
        }
        if (dp[buy][idx]!=-1) return dp[buy][idx];
        int profit=0;
        if (buy){
                 profit =max(-v[idx]+solve(idx+1,0,v,n,dp),0+solve(idx+1,1,v,n,dp));
        }
        else {
             profit =max(v[idx]+solve(idx+1,1,v,n,dp),0+solve(idx+1,0,v,n,dp));
        }

        return  dp[buy][idx]=profit ;
    }
    int maxProfit(vector<int>& v) {
        int n=v.size();  
        vector<vector<int>>dp(2,vector<int>(n,-1));
         return solve (0,1,v,n,dp);
    }
};