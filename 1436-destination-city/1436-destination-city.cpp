class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
    unordered_set<string>s;
    for (auto it:paths){
        s.insert(it[0]);
    }
    string ans="";
    for (auto it:paths){
        string s1=it[0];
        string s2=it[1];
        if (s.find(s1)==s.end()){
            ans= s1;
            break;
        }
        if (s.find(s2)==s.end()){
            ans= s2;
            break;
        }
    }
    return ans;
    
    }
};