class Solution {
public:
    int minPartitions(string s ) {
        int ans =-1;
        for (int i =0;i<s.length();i++){
            int x= s[i]-'0';
            ans= max(ans,x);
        }
        return ans;
        
    }
};