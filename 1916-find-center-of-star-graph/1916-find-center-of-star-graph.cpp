class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,int>m;
        for (auto it:edges){
            int x1=it[0];
            int x2=it[1];
            m[x1]++;
            m[x2]++;
            
        }
        for (auto it :m){
            if (it.second==m.size()-1) return it.first;
 
        }
        return -1;
    }
};