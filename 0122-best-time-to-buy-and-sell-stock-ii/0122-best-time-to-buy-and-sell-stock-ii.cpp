class Solution {
public:
    int maxProfit(vector<int>& v) {
        int ans =0;
        for (int  i=0;i<v.size()-1;i++){
            if (v[i+1]-v[i]>=0) ans+=v[i+1]-v[i];
        }
        return ans ;
    }
};