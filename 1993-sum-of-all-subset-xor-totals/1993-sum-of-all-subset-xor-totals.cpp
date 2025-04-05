class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result |= num;
        }
        return result << (nums.size() - 1);
    }
};

// class Solution {
// public:
//     int subsetXORSum(vector<int>& nums) {
//         int ans=0;
//         for (int i =0;i<nums.size();i++){
//             int xo=0;
//             for (int j=i;j<nums.size();j++){
//                 xo^=nums[j];
//                 ans+=xo;
//             }

//         }
//         return ans;
//     }
// };