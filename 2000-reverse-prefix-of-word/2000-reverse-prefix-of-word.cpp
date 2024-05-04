class Solution {
public:
    string reversePrefix(string s, char ch) {
        int ans =0;
        for (int i=0;i<s.length();i++){
            if (s[i]==ch){
                ans=i+1;
                break;
            }
        }
        reverse(s.begin(),s.begin()+ans);
        return s;
    }
};