class Solution {
public:
    bool canJump(vector<int>& v) {
        int n = v.size();
        vector<bool>dp(n,false);  
        dp[n - 1]=true;
        for (int i=n-2;i >=0;--i){
            int furthestJump=min(i+v[i],n-1);
            for (int j=i+1;j<= furthestJump;++j){
                if (dp[j]){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[0];
    }
};
