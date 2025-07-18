class Solution {
public:
    int solve (int i,int prev ,vector<int>&v,vector<vector<int>>&dp){
        if (i>=v.size()) return 0;
        if (dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=0,ntake=0;
        if (prev==-1 ||  v[prev]<v[i])
        take=1+solve(i+1,i,v,dp);
        ntake =  solve(i+1,prev,v,dp);
        return dp[i][prev+1] =max(take,ntake);

    }
    int lengthOfLIS(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
        
    }
};