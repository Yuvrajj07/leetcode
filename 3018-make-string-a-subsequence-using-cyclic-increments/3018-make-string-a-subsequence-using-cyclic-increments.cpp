class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int s1=str1.length(),s2=str2.length();
        int cnt=0;
        for (int i=0;i<s1 && cnt<s2;i++){
            if ((str1[i]==str2[cnt]) || (str1[i]+1==str2[cnt]) ||(str1[i]-25==str2[cnt]) ){
                cnt++;
            }

        }
        if (cnt==s2) return true;
        return false;
    }
};