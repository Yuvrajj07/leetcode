class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        vector<int>v;
        int ans=0;
        for (auto it:nums){
            ans^=it;
        }

        int z=(2<<maximumBit-1)-1; // maxximum possible xor of the array is stored in z;
        // cout<<z+1<<endl;
        for (int i =nums.size()-1;i>=0;i--){
           int p=ans^z;
           v.push_back(p);
           ans=ans ^nums[i]; 
        }
        return v;
    }
};