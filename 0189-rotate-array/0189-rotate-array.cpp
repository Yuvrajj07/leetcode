class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int z= nums.size();
         k= k%z;
        reverse(nums,0,z-1);
        reverse(nums,0,k-1);
        reverse(nums,k,z-1);
        
    }
    void reverse(vector<int>&nums,int s,int e){
        while (s<=e){
            swap(nums[s],nums[e]);
            s++;
            e--;
        }

    }
};