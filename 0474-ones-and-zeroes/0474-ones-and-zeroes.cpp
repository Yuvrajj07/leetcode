class Solution {
public:
    int dp[601][101][101];
    int solve(int idx ,int m,int n,vector<pair<int,int>>&v){
        if (idx>=v.size())return 0;
        if (dp[idx][m][n]!=-1) return dp[idx][m][n];
        int take=0,ntake=0;                
        
        if (m>=v[idx].first && n>=v[idx].second ) take =1+solve(idx+1,m-v[idx].first,n-v[idx].second,v);
         ntake =solve(idx+1,m,n,v);
        return dp[idx][m][n]=max(take,ntake);
    }
    int findMaxForm(vector<string>& str, int m, int n) {
        vector<pair<int,int>>v;
        for (int i=0;i<str.size();i++){
            int z=0,o=0;
            for (int j=0;j<str[i].size();j++){
                if (str[i][j]=='0') z++;
                else o++;
            }
            v.push_back({z,o});
        }
        memset(dp,-1,sizeof(dp));
        return solve(0,m,n,v);
    }
};