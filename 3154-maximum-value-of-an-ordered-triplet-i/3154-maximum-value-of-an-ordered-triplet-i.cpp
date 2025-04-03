class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        for (int k = 2; k < n; k++) {
            int maxPrefix = nums[0];
            for (int j = 1; j < k; j++) {
                res = max(res, (long long)(maxPrefix - nums[j]) * nums[k]);
                maxPrefix = max(maxPrefix, nums[j]);
            }
        }
        return res;
    }
};

//..............BRUTE FORCE .............
// class Solution {
// public:
//     long long maximumTripletValue(vector<int>& nums) {
//         int n=nums.size();
//         long long res=0;
//         for (int i=0;i<n;i++){
//             for (int j=i+1;j<n;j++){
//                 for (int k=j+1;k<n;k++){
//                     res=max(res,(long long)(nums[i]-nums[j])*nums[k]);
//                 }
//             }
//         }
//         return res;
//     }
// };