class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>>v;
        for(int i =0;i<names.size();i++){
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end());
        vector<string>ans;
        for (auto it:v){
            ans.push_back(it.second);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};