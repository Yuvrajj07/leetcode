class Solution {
public:
    vector<vector<double>>dp;
    double solve(int a,int b){
        if (a<=0 && b>0) return 1.0;
        if (a<=0 && b<=0) return .5;
        if (a>0 && b<=0) return 0.0;
        if (dp[a][b]!=-1.0) return dp[a][b];
        double o1=solve(a-4,b-0);
        double o2=solve(a-3,b-1);
        double o3=solve(a-2,b-2);
        double o4=solve(a-1,b-3);
        return dp[a][b]= .25*(o1+o2+o3+o4);
    }
    double soupServings(int n){ 
      if (n > 4800) return 1.0;
        n=ceil(n/25.0); // to avoid memory limit exceed 
        dp.assign(n+1,vector<double>(n+1,-1.0));
        double ans=solve(n,n);
        return ans;  
    }
};