class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0;
        for (int  i=0;i<words.size();i++){
            string s1=words[i];
            for (int j =i+1;j<words.size();j++){
                string s2= words[j];
                
                   if (s1.length() <= s2.length()) {
                        string st=s2.substr(0,s1.length());
                        string en=s2.substr(s2.length()-s1.length(),s1.length());
                        if (st==en && st==s1) ans++;

                    }
            }
                
            }
        
        return ans;

    }
};