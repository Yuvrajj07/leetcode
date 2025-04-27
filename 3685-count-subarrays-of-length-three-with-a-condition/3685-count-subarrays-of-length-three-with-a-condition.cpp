class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int ans=0;
        for (int i=0;i<nums.size()-2;i++){
            float x=nums[i]+nums[i+2];
            float z=nums[i+1]/2.0;
            cout<<x<<" "<<z<<endl;
            if (z==x) ans++;
        }
        return ans;
    }
};