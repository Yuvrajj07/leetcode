class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans="";
        string s1=strs[0],s2 =  strs[strs.size()-1];
        int p1=0,p2=0;
        while (p1<s1.length() && s1[p1]==s2[p2]){
            ans+=s1[p1];
            p1++;
            p2++;
        }
        return ans;
    }
};