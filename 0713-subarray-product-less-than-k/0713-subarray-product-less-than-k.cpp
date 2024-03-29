//          -------------------------BRUTE FORCE ---------------- 

// class Solution {
// public:
//     int numSubarrayProductLessThanK(vector<int>& v, int k) {
//         if(k==0) return 0;
//         long long int  n=v.size(),ans=0;
//         int i=0;
//         while (i<n){
//             long long  p=1;
//             int j=i;
//             while (j<n){
//                 p=p*v[j];
//                 if(p<k) ans++;
//                 j++;
//             }
//             i++;
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int i =0,j =0;
        long long int ans =1; 
        int count =0;
        if(k<=1) return 0;
        while(j<nums.size()){
          ans *= nums[j];
          while(ans >= k){
            ans = ans /nums[i];
            i++;
          }
          count += j-i+1;
          j++;

        }

        return count;
    }
};
