class Solution {
public:
    void solve (int i ,int prev,vector<vector<int>>&ans,vector<int>&temp,vector<int>&v){
        if (i==v.size()) return ;
        unordered_set<int> used;
        for (int j=i;j<v.size();j++){
        if ((prev==-1 || v[prev]<=v[j] )&& !used.count(v[j])){
            used.insert(v[j]);
            temp.push_back(v[j]);
            if (temp.size()>=2) ans.push_back(temp);
             solve(j+1,j,ans,temp,v);
            temp.pop_back();
        }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& v) {
        int n= v.size();   
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,-1,ans,temp,v);
        return ans;
    }
};