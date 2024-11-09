class Solution {
public:
    int maximumGap(vector<int>& nums) {
        multiset<int>m;
        for (auto it:nums){
            m.insert(it);
        }
        if (m.size()<2) return 0;
        int ans=0;
        int diff=*m.begin();
        m.erase(m.begin());
        for (auto it :m){
            int z= abs(it-diff);
            ans =max(ans,z);
            diff=it;
            m.erase(m.begin());
        }
        return ans ;
    }
};