class Solution {
public:
    long long dividePlayers(vector<int>&v) {
        vector<long long >ans;
        sort(v.begin(),v.end());   
        int x=v.size();
        int z=v[0]+v[x-1];
        for (int i =0;i<x/2;i++){
            int s=v[i]+v[x-i-1];
            if (s!=z) return -1;
            ans.push_back(v[i]*v[x-i-1]);
        }

 long long l=0;
    for (auto it :ans){
        // cout<<i <<" ";
        l+=it;
    }
    return l;
    }
};