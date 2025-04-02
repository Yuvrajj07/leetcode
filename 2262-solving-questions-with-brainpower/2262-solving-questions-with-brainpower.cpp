class Solution {
public:
long long solve(int s,int n,vector<pair<int,int>>&v,vector<long long>&dp){
    if (s>=n) return 0;
    if(dp[s]!=-1) return dp[s];
    return   dp[s]=max(v[s].first+solve(s+v[s].second+1,n,v,dp),solve(s+1,n,v,dp));
}
long long mostPoints(vector<vector<int>>& v1) {
        int n=v1.size();
        vector<long long >dp(n+1,-1);
        vector<pair<int,int>>v;
        for(auto it :v1){
            v.push_back({it[0],it[1]});
        }
         return solve (0,n,v,dp);
    }
};