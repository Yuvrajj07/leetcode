class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int ans=1;
        int z=0;
        for (int i =0;i<nums.size();i++){
            if (nums[i]==0) z++;
        }
        if (z==1){
            for (int i =0;i<nums.size();i++){
                if (nums[i]!=0) ans*=nums[i];
            }
            for (int i =0;i<nums.size();i++){
                if (nums[i]==0) nums[i]=ans;
                else nums[i]=0;
            }
        }
        else if (z>1){
            for (int i =0;i<nums.size();i++){
             nums[i]=0;
            }
        }
        else {
            for (int i =0;i<nums.size();i++){
            ans*=nums[i];
            }
            for (int i =0;i<nums.size();i++){
            nums[i]=ans/nums[i];
            }
            
        }
        return nums;
    }
};