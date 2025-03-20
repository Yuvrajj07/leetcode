class Solution {
public: 
    int solve(vector<int>v,int n,vector<int>&dp){
        if (n<=0)  return 0;
        if (dp[n]!=-1)  return dp[n];
       
        int loot=solve(v,n-2,dp)+v[n-1];
        int nloot=solve(v,n-1,dp);
        return  dp[n]=max(loot,nloot); 
    } 
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,-1);
        return solve(nums,n,dp);
        // dp[0]=0;
        // dp[1]=nums[0];
        // for (int i =2;i<=n;i++){
        //     dp[i]=max(nums[i-1]+dp[i-2],dp[i-1]);
        // }
        // return dp[n];
    }
};