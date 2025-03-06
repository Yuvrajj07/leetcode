class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_map<int,int>m;
        for (auto it:grid){
            for (auto i:it){
                m[i]++;
            }
        }
        int n=grid.size();
        vector<int>ans;
        for (auto it:m){
            if (it.second==2) ans.push_back(it.first);
        }
        for (int i =1;i<=n*n;i++){
            if (m.find(i)==m.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};