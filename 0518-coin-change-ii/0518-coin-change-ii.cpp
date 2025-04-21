class Solution {
public:
    int solve(int i ,int n,int amount ,vector<int>&v,vector<vector<int>>&dp){
        if (amount==0) return 1;
        if (i==n ||  amount<0) return 0;
        if (dp[i][amount]!=-1) return dp[i][amount];
        int take=solve(i,n,amount-v[i],v,dp);
        int ntake=solve(i+1,n,amount,v,dp);
        return dp[i][amount]= take+ntake;        
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(0,n,amount,coins,dp);
    }
};
