class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int ,int>m;
        for (int i =0;i<nums.size();i++){
            m[nums[i]]=m[nums[i]]+1;
        }
        int ans=0;
        for (auto it:m){
            if (it.second>=2) ans=it.first;
        }
        return ans;
    }
};