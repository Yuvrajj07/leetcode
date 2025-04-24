class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>s;
        int n1=nums.size();
        for (auto it :nums){
            s.insert(it);
        }
        int n= s.size();
        unordered_map<int,int>m;
        int i =0,j=0,ans=0;
        while (j<n1){
            m[nums[j]]++;
            while (m.size() == n) {
                ans += (n1-j);
                m[nums[i]]--;
                if (m[nums[i]] == 0) m.erase(nums[i]);
                i++;
            }
            j++;       
        }
        return ans;
    }
};
