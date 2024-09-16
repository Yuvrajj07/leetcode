class Solution {
public:
    int countConsistentStrings(string s, vector<string>& words) {
        unordered_map<char,int>m;
        for (int i =0;i<s.length();i++){
            m[s[i]]++;
        }
        int z= m.size(),ans=0;
        unordered_map<char,int>m1=m;
        for (auto it :words){
        unordered_map<char,int>m1=m;
            string s1=it;
            for (int i=0;i<s1.length();i++){
                m1[s1[i]]++;
            }
            if (m1.size()==m.size()) ans++;

        }
        return ans;
    }
};