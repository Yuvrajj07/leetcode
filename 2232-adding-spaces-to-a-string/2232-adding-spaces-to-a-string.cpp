class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        vector<char>v;
        int j=0;
        for (int i =0;i<s.length();i++){
            if (   j<spaces.size() && spaces[j]==i){
                v.push_back(' ');
                j++;
            }
                v.push_back(s[i]);
            
        }
        string ans="";
        for (auto it :v){
            ans+=it;
        }
        return ans;
        
    }
};