// class Solution {
// public:
//     int  ans=0;
//     int findTargetSumWays(vector<int>& nums, int target) {
//         calc(nums,0,0,target);
//         return ans;
//     }
//     private:
//     void calc(vector<int>v,int sum ,int idx,int target){
//         vector<int>dp(v.size()+1,-1);
//         if (dp[idx]!=-1) return dp[idx];
//         if (idx==v.size()){
//             if (target==sum ) ans++;
//         }
//         else {
//             calc(v,sum+v[idx],idx+1,target);
//             calc(v,sum-v[idx],idx+1,target);
//             dp[idx]=sum;
//         }
//     }
// };


class Solution {
public:
    
    int solve(int i,int sum ,int target ,vector<int>v,vector<vector<int>>&dp,int mx){
        if (i==v.size()){
            if (sum ==target) return 1;
            else return 0;
        }
        if (dp[i][sum+mx]!=-1) return dp[i][sum+mx];
        int include=solve(i+1,sum+v[i],target,v,dp,mx);
        int exclude = solve(i+1,sum-v[i],target,v,dp,mx);
        return  dp[i][sum+mx]= include +exclude;     
        }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int mx= accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n+1,vector<int>(2*mx+1,-1));
        return solve(0,0,target,nums,dp,mx);
    }

};
// class Solution {
// public:
//     int totalSum;

//     int findTargetSumWays(vector<int>& nums, int target) {
//         totalSum = accumulate(nums.begin(), nums.end(), 0);
//         vector<vector<int>> memo(nums.size(), vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
//         return calculateWays(nums, 0, 0, target, memo);
//     }

//     int calculateWays(vector<int>& nums, int currentIndex, int currentSum,int target,vector<vector<int>>& memo) {
//         if (currentIndex == nums.size()) {
//             if (currentSum == target) {
//                 return 1;
//             } 
//             else {
//                 return 0;
//             }
//         } 
//         else {
//             if (memo[currentIndex][currentSum + totalSum] !=numeric_limits<int>::min()) {
//                 return memo[currentIndex][currentSum + totalSum];
//             }
//             int add =calculateWays(nums, currentIndex + 1,currentSum + nums[currentIndex], target, memo);
//             int subtract =calculateWays(nums, currentIndex + 1,currentSum - nums[currentIndex], target, memo);
//             memo[currentIndex][currentSum + totalSum] = add + subtract;
//             return memo[currentIndex][currentSum + totalSum];
//         }
//     }
// };