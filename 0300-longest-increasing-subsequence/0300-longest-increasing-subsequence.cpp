class Solution {
public:
    int solve(int i,int n, vector<int>&v,int prev,vector<vector<int>>&dp){
        if (i>=n) return 0;
        if (dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take =0;
        if (prev==-1 || v[i]>v[prev]){
            take =1+solve(i+1,n,v,i,dp);
        }
        int ntake = solve(i+1,n,v,prev,dp);
        return dp[i][prev+1]=max(take,ntake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n,nums,-1,dp);
    }
};
