// class Solution {
// public:
//     long long minSum(vector<int>& nums1, vector<int>& nums2) {
//         int s1=accumulate(nums1.begin(),nums1.end(),0);
//         int s2=accumulate(nums2.begin(),nums2.end(),0);
//         int z1=0,z2=0;
//         for (auto it :nums1){
//             if (it==0) z1++;
//         }
//         for (auto it :nums2){
//             if (it==0) z2++;
//         }
//         if(s1!=s2 && s1+sz1>)
//         int sz1=((z1+1)*z1)/2;
//         int sz2=((z2+1)*z2)/2;
//         return max(s1+sz1,s2+sz2);
        
        
                
//     }
// };

class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;
        for (int i : nums1) {
            sum1 += i;
            if (i == 0) {
                sum1++;
                zero1++;
            }
        }
        for (int i : nums2) {
            sum2 += i;
            if (i == 0) {
                sum2++;
                zero2++;
            }
        }
        if (!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};