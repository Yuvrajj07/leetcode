class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
         int  x= nums.size(),sum=0,ans=0;
          if (nums[x-1]==goal) ans++;
         for (int i=0;i<x-1;i++){
            if (nums[i]==goal) {
                ans++;
            }
            int j=i+1;
            sum=0;
            sum+=nums[i];
            while (sum<=goal && j<x){
                sum+=nums[j];
                if (sum==goal) ans++;
                j++;
            }
         }
        
         return ans;     
    }
};