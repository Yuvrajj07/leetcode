class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1=s1.length(),n2=s2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        for (int i =0;i<n1;i++) dp[i][0]=0;
        for (int i =0;i<n2;i++) dp[0][i]=0;
        for (int i =1;i<=n1;i++){
            for (int j=1;j<=n2;j++){
                if (s1[i-1]==s2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
            string ans="";
            int i =n1,j=n2;
            while (i>0 &&  j>0){
                if (s1[i-1] ==s2[j-1]){
                    ans+=s1[i-1];
                    i--;
                    j--;
                }
                else if (dp[i-1][j]>dp[i][j-1]){
                    ans+=s1[i-1];
                    i--;
                }
                else {
                    ans+=s2[j-1];
                    j--;
                }
            }  
        
          while (i>0){
                ans+=s1[i-1];
                i--;
            }
            while (j>0){
                ans+=s2[j-1];
                j--;
            }
          
        reverse (ans.begin(),ans.end());
        return ans;
    }
};