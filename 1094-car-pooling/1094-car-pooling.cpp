class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
         map<int,int>m;
        for ( auto log : trips) {
            m[log[1]]+=log[0];
            m[log[2]]-=log[0]; 
        }
        int ans =0;
        for (auto it:m){
             ans+=it.second;
             if(ans>capacity){
                return false ;
             }
        }
        return true;
    }
};
