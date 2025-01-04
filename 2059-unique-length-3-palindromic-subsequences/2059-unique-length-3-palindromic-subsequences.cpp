class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int i=0,ans=0;
        unordered_set<char>f;
        while (i<s.length()-2){
            if (f.find(s[i])==f.end()){
                f.insert(s[i]);
            
                int j=s.length()-1;
                bool chk=false;
                while (s[j]!=s[i] && j-i>2){
                    j--;
                    
                }
                if (s[j]==s[i]) chk=true;
                j--;
                unordered_set<char>c;
                while (j>i && chk){
                    c.insert(s[j]);
                    j--;

                }
                ans+=c.size();
                i++;
            }
            else {
                i++;
            }
            
        }
        return ans;

    }
};