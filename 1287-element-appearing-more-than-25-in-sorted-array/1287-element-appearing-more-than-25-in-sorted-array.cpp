class Solution {
public:
    int findSpecialInteger(vector<int>&v) {
        unordered_map<int,int>m;
        for (int i=0;i<v.size();i++){
            m[v[i]]=m[v[i]]+1;
        }
        int z= v.size()/4;
        int ans=0;
        for(auto it:m){
            if(it.second>z) ans= it.first;
        }
        return ans;
        
        
    }
};