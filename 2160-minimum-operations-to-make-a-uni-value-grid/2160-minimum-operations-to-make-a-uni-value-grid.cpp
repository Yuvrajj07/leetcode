class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
    vector<int>v;
    for (auto it :grid){
        for (auto i:it){
            v.push_back(i);
        }
    }
    sort(v.begin(),v.end());
    int mid=v[v.size()/2];
    int ans=0;
    for (auto it :v){
        if (it%x!=mid%x) return -1;
        ans+=abs(mid-it)/x;
    }
    return ans;


    
    }
};