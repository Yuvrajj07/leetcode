class Solution {
public:
    int maxScore(string s) {
        int z=0,o=0;
        for (int i=0;i<s.length();i++){
            if (s[i]=='1') o++;
            else z++;
        }
        int ans =INT_MIN;
        int n=s.length();
        int t1=0,t0=0;
         int score;
        for (int i =0;i<s.length()-1;i++){
            if (s[i]=='1') t1++;
            else t0++;
            score=t0+(o-t1);
            ans=max(ans,score);
        }
        ans=max(ans,score);
        return ans;

    }
};