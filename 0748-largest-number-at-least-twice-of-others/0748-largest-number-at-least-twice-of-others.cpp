class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0; 
        int mx = -1, secondMax = -1, idx = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > mx) {
                secondMax = mx;
                mx = nums[i];
                idx = i;
            } else if (nums[i] > secondMax) {
                secondMax = nums[i];
            }
        }
        if (mx >= 2 * secondMax) {
            return idx;
        }
        return -1;
    }
};



// class Solution {
// public:
//     int dominantIndex(vector<int>& nums) {
//         int arr[101]={0};
//         int mx=0,idx=0;
//         for (int i=0;i<nums.size();i++){
//             arr[nums[i]]++;
//             if (nums[i]>mx){
//                 mx=nums[i];
//                 idx=i;
//             }
//         }      
//         int z=mx/2;
//         for (int i =z;i<idx;i++){
//             if (arr[i]>=1) return  -1 ;
//         }
//         return idx;
//     }
// };