class Solution {
public:
    int solve(vector<int>v1,vector<int>&dp){
        int n=v1.size();
        dp[0]=0;
        dp[1]=v1[0];
        for (int i=2;i<=n;i++){
            dp[i]=max(dp[i-2]+v1[i-1],dp[i-1]);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        vector<int>v1,v2;
        for (int i =0;i<nums.size();i++){
            if (i!=0){
                v1.push_back(nums[i]);
            }
            if (i!=n-1){
                v2.push_back(nums[i]);
            }
        }
        cout<<v1.size()<<" "<<v2.size()<<endl;
        int x=solve(v1,dp1);
        int y=solve(v2,dp2);
        return max(x,y);
    }
};