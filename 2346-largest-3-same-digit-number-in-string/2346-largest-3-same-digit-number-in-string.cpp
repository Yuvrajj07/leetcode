class Solution {
public:
    string largestGoodInteger(string s) {
        int ans=-1;
        for (int i=0;i<s.length()-2;i++){
            if (s[i]==s[i+1] && s[i+1]==s[i+2]) ans=max(ans,s[i]-'0'); 
        }    
        string s1= to_string(ans);
        return ans!=-1 ? s1+s1+s1: "";
    }

};