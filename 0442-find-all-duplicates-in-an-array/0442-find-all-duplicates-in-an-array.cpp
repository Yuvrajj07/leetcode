class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int >m;
        // for (auto it:nums){
        //     // m[nums[it]]+=1;
        //     m[nums[it]]=m[nums[it]]+1;
        // }
        for (int i =0;i<nums.size();i++){
             m[nums[i]]=m[nums[i]]+1;
        }
        vector<int>ans;
        for (auto i:m){
            if (i.second==2) ans.push_back(i.first);
        }
        return ans;
    }
};