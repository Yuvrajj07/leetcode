class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int mx= *max_element(nums.begin(),nums.end());
        int mn=1;
        int ans =mx;
        while (mn<mx){
            int penalty= (mn+mx)/2;
            int ops=0;
            for (int i=0;i<nums.size();i++){
                if (nums[i]>penalty){
                    if (nums[i]%penalty==0) {
                        ops=ops+nums[i]/penalty-1;
                    }
                    else {
                        ops=ops+nums[i]/penalty;
                    }
                }
            }
            if (ops<=maxOperations){
                ans=penalty;
                mx=penalty;
            }
            else {
                mn=penalty+1;
            }
        }
        return ans;
    }
};