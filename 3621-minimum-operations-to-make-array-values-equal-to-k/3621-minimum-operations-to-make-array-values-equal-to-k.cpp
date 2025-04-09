class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int>s;
        for (int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int ans=0;
        for (auto it:s){
            if (it==k) ans++;
            if (it<k) return -1;
        }
        return s.size()-ans;
        
    }
};