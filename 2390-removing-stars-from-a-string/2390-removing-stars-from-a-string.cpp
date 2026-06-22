class Solution {
public:
    string removeStars(string s) {
     int st=0;
     string ans="";
     for (int i =s.length()-1;i>=0;i--){
        if(s[i]=='*')st++;
        else if (s[i]!='*' && st>0) st--;
        else ans+=s[i]; 
     }
     reverse (ans.begin(),ans.end());  
     return ans;
    }
};