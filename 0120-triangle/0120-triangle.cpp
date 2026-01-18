// class Solution {
// public:
//     int solve (vector<vector<int>>&v,int i,int j,vector<vector<int>>&dp){
//         // if (i>=v.size() ||  j>=v[i].size()) return 0;
//         if (i == v.size() - 1) return v[i][j];
//         if (dp[i][j]!=-1) return dp[i][j];
//         int curr=0,n=0;
//         curr=v[i][j]+solve(v,i+1,j,dp);
//         n=v[i][j]+solve(v,i+1,j+1,dp);
//         return dp[i][j]=min(curr,n);
//     }
//     int minimumTotal(vector<vector<int>>&v) {
//         vector<vector<int>>dp(v.size(),(vector<int>(v[v.size()-1].size(),-1)));
//         return solve (v,0,0,dp);
//     }
// };


class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
        vector<int> dp = v.back();

        for (int i = v.size() - 2; i >= 0; i--) {
            for (int j = 0; j < v[i].size(); j++) {
                dp[j] = v[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
