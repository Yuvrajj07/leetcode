class Solution {
public:
    // int solve(int s,int n,vector<int>v,int i ){
    //     if (s>=n) return 0;
    //     return min(solve(s+v[i],n,v,i+1),solve(s+v[i],n,v,i+v[i]));
    // }
    int solve(int i, int n, vector<int>& nums,vector<int>& dp) {
        if (i>=n-1)return 0; 
        if (dp[i]!=-1) return dp[i];
        int minJumps=INT_MAX;
        for (int jump=1;jump<=nums[i];jump++) { // Try all possible jumps
            if (i+jump<n){
                int res=solve(i+jump,n,nums,dp);
                if (res!= INT_MAX) { 
                    minJumps = min(minJumps, res + 1); 
                }
            }
        }
        return dp[i]=minJumps;
    }
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1,-1);
        return solve(0,n,nums,dp);
    }
};
    
