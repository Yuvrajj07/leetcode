class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ans=0,sum=0;
        for (int i =0;i<nums.size();i++){
            sum+=nums[i];
        }
        int lsum =0,rsum =0;

        for (int i=0;i<nums.size();i++){
            rsum =sum -lsum -nums[i];
            if (lsum == rsum ) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};