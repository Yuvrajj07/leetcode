class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (int i=0;i<words.size();i++){
            string s=words[i];
            string s2=s;
            reverse(s.begin(), s.end());
            if (s==s2) return s;
        }
        return "" ;
    }
};