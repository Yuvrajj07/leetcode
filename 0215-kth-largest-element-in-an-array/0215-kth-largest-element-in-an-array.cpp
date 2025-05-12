class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        multiset<int>m;
        for (auto it:nums){
            m.insert(it);
        }
        k--;
        while  (k--){
            auto it=m.end();
            it--;
            m.erase(it);
        }
        return *m.rbegin();
    }
};