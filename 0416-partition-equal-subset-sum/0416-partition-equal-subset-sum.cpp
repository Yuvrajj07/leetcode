class Solution {
public:
    bool  solve(int i,int sum,int target,vector<int>v, vector<vector<int>>&dp){
        if (sum==target) return  true;
        if (i==v.size() || sum>target) return false;
        if (dp[i][sum]!=-1) return dp[i][sum];
        else dp[i][sum]=(solve(i+1,sum+v[i],target,v,dp) || solve(i+1,sum,target,v,dp));
        return dp[i][sum]; 
    }
    bool canPartition(vector<int>& v) {
        int n=v.size();
        int sum =accumulate(v.begin(),v.end(),0);
        if (sum%2!=0) return false;
        int target =sum/2;
        vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        return solve(0,0,target,v,dp);
  }
};