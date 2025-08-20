class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos,
                vector<int>& rowCosts, vector<int>& colCosts) {
        int ans = 0;
        int i = startPos[0], j = startPos[1];
        int x = homePos[0], y = homePos[1];

        while (i < x) ans += rowCosts[++i];
        while (i > x) ans += rowCosts[--i];

        while (j < y) ans += colCosts[++j];
        while (j > y) ans += colCosts[--j];

        return ans;
    }
};









// class Solution {
// public:
//     int solve (int i,int j,int x,int y,vector<int>&r,vector<int>&c,vector<vector<int>>&dp){
//         if(i==x && j==y) return 0;
//         if (dp[i][j]!=-1) return dp[i][j];
//         int u=INT_MAX,l=INT_MAX,d=INT_MAX,r1=INT_MAX;
//         if (i>=1) u= r[i-1]+solve (i-1,j,x,y,r,c,dp);
//         if (i<r.size()-1)d= r[i+1]+solve (i+1,j,x,y,r,c,dp);
//         if (j<c.size()-1)r1= c[j+1]+solve (i,j+1,x,y,r,c,dp);
//         if (j>=1) l= c[j-1]+solve (i,j-1,x,y,r,c,dp);
//         return dp[i][j]=min({u,d,r1,l});

//     }
    
//     int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
//         int n=rowCosts.size(),m=colCosts.size();
//         vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
//         int x=homePos[0],y=homePos[1];
//         int i =startPos[0],j=startPos[1];
//         return solve(i,j,x,y,rowCosts,colCosts,dp);
//     }
    
// };