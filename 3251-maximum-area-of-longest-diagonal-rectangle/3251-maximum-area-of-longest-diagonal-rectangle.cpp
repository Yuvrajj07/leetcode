class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& v) {
        int  ans=0;
        long long d1=0,mx=-1;
        for (auto it :v){
          d1 =1LL *it[0]*it[0]+it[1]*it[1];
            if (d1>mx || (d1==mx && it[0]*it[1]>ans)) {
                ans=it[0]*it[1];
                mx=d1;

            }
        }
        return ans;
    }
};