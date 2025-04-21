//.....................................TLE CODE ......................................
// class Solution {
// public:
//     int solve(int i ,int n,int tar,vector<int>&v,vector<vector<int>>&dp){
//         if (tar==0) return 0;
//         if (i==n || tar<0) return -1;
//         if (dp[i][tar]!=-1) return dp[i][tar];
//         int take = solve(i+1,n,tar-v[i],v,dp);
//         int ntake = solve(i+1,n,tar,v,dp);
//          if (take != -1) take += 1;
//         return dp[i][tar]= max(take,ntake);
//     }
//     int lengthOfLongestSubsequence(vector<int>& nums, int target) {
//         int n= nums.size();
//         vector<vector<int>>dp(n,vector<int>(target+1,-1));
//         return solve(0,n,target,nums,dp);
//     }
// };


//......................... COPIED CODE FOR TABULATION...............................

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, -1);
        dp[0] = 0; // 0 elements needed to make sum 0

        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--) {
                if (dp[j - nums[i]] != -1) {
                    dp[j] = max(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }

        return dp[target];
    }
};
