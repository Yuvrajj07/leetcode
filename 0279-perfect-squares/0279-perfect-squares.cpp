class Solution {
public:
    static const int INF = 1e9;
    int solve (int n,int i,vector<vector<int>>&dp){
        if (n==0) return 0;
        if (dp[n][i]!=-1) return dp[n][i];
        if (i*i>n) return INF;
        long long  take=99999,ntake=99999;
        take= 1+solve(n-(i*i),i,dp);
        ntake= solve(n,i+1,dp);
        return dp[n][i]=min (take,ntake);
    } 
    int numSquares(int n) {
        vector<vector<int>>dp(n+1,(vector<int>(sqrt(n)+2,-1)));
        return solve (n,1,dp);
    }
};

/*
class Solution {
public:
    int solve (int n,int i){
        if (n==0) return 0;
        if (i*i>n) return INT_MAX;
        int take=INT_MAX,ntake=INT_MAX;
        int res= solve(n-(i*i),i);
        if (res!=INT_MAX) take=1+res;
        ntake= solve(n,i+1);
        return min (take,ntake);
    } 
    int numSquares(int n) {
        return solve (n,1);
    }
};
*/