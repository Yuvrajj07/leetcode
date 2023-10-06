class Solution {
public:
    int searchInsert(vector<int>&v, int target) {
        int n=v.size();
        int s=0;
        int e=n-1;
        int ans= lower_bound(v.begin(),v.end(),target)-v.begin();
        return ans;
    }
};