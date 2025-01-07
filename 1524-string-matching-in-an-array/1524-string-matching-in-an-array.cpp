class Solution {
public:
    vector<string> stringMatching(vector<string>& v) {
        vector<string>ans;
        for (int i =0;i<v.size();i++){
            string s1=v[i];
            for (int j=0;j<v.size();j++){
                string s2=v[j];
                if(s2.find(s1)!=string::npos && i!=j){
                    ans.push_back(s1);
                    break;
                }
            }
        }
        return ans;
    }
};