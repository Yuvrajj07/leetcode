class Solution {
public:
    int solve (int i ,int prev,int sign,vector<int>&nums, vector<vector<vector<int>>>&dp){
        if (i==nums.size()) return 0;
        if (dp[i][prev+1][sign+1]!=-1) return dp[i][prev+1][sign+1];
        int take=0,ntake=0;
        ntake=solve(i+1,prev,sign,nums,dp);
        if (prev==-1){
            take=1+solve(i+1,i,0,nums,dp);
        }
        else {
             int currD =nums[i]-nums[prev];
            if ((currD > 0 && sign != 1) || (currD < 0 && sign != -1)) {
                take = 1 + solve(i + 1, i, (currD > 0 ? 1 : -1), nums, dp);
            }
        }

        return dp[i][prev+1][sign+1]=max(take,ntake);
    }
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        // vector<int>dp(n+1,-1);
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(3,-1)));
        return solve(0,-1,0,nums,dp);

        
    }
};