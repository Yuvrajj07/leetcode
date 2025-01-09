class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans=0;
        for (int i =0;i<words.size();i++){
            if (pref.length()<=words[i].length()){
                string s1=words[i].substr(0,pref.length());
                if (s1==pref) ans++;
            }
        }
        return ans;

    }
};