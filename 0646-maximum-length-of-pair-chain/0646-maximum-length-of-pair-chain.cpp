class Solution {
public:
    int solve(int i,int prev,vector<vector<int>>&v,vector<vector<int>>&dp){
        if (i>=v.size()) return 0;
        if (dp[i][prev+1]!=-1) return dp[i][prev+1]; 
        int take =0;
        if (prev==-1 || v[prev][1]<v[i][0])
            take =1+solve(i+1,i,v,dp);
        int ntake =solve(i+1,prev,v,dp);
        return dp[i][prev+1]= max(take,ntake);         
    }
    int findLongestChain(vector<vector<int>>& v) {
        int n=v.size(),ans=0;
        sort(v.begin(),v.end());
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        ans=max(solve(0,-1,v,dp),ans);

        return ans;

        
    }
};