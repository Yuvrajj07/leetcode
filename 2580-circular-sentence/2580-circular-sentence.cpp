class Solution {
public:
    bool isCircularSentence(string s) {
        int x=s[0],y=s[s.length()-1];
        if (x!=y) return false ;
        for (int it =0;it<s.length();it++){
            if ((s[it]>='a' && s[it]<='z') || (s[it]>='A' && s[it]<='Z') || s[it]==32){

            }
            else {
                return false;
            }
            if (s[it+1]==32 &&(s[it]!=s[it+2])){
                return false;
            }
        }
        return true;
    }
};