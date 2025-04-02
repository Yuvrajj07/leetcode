class Solution {
public:
    bool solve(int i ,int n,vector<int>&v,vector<int>&dp){
        if (i>=n-1) return true;
        if (dp[i]!=-1) return dp[i];
        for (int jump=1;jump<=v[i];jump++){
            if (i+jump<n &&  solve(i+jump,n,v,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool canJump(vector<int>& v) {
        int n=v.size();
        vector<int>dp(n,-1);
        return  solve (0,n,v,dp);
    }
};

