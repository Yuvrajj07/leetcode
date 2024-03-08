class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;
        for (int i =0;i<nums.size();i++){
            m[nums[i]]=m[nums[i]]+1;
        }
        int mx=0;
        for (auto it:m){
            if (it.second>mx){
                mx=it.second;
            }
        }
        int ans=0;
        for (auto it :m){
            if (it.second==mx){
                ans+=it.second;
            }
        }
        return ans;
    }
};