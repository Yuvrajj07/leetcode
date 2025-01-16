// class Solution {
// public:
//     int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
//         int x=0,y=0;
//         unordered_map<int,int>m1;
//         unordered_map<int,int>m2;
//         int ans=0;
//         for (auto it:nums1){
//             if (it!=0)
//             m1[it]++;
//         }
//         for (auto it:nums2){
//             if (it!=0)
//             m2[it]++;
//         }
//         for (auto it:m1){
//             if (it.second%2!=0) x++;
//         }
//         vector<int>c;

//         for (auto it:m2){
//             if (it.second%2!=0) y++;
//         }
//         cout<<x<<" "<<y<<endl;
//         if (x%2==0 && y%2==0) return ans;
//             else {
//                 if (x%2!=0){
//                     for (auto it:m1){
//                         if (it.second%2!=0) c.push_back(it.first);
//                     }
//             }
//                 if (y%2!=0){
//                     for (auto it:m2){
//                         if (it.second%2!=0) c.push_back(it.first);
//                     }
//         }
//         for (auto it :c){
//             ans^=it;
//         }
//     }

//         return ans;
//     }
// };


class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(); // Size of nums1
        int m = nums2.size(); // Size of nums2
        int xor1 = 0, xor2 = 0;
        for (int num : nums1) {
            xor1 ^= num;
        }
        for (int num : nums2) {
            xor2 ^= num;
        }

        // If nums2 is odd, all elements of nums1 will contribute to the final XOR
        // If nums1 is odd, all elements of nums2 will contribute to the final XOR
        int result = 0;
        if (m % 2 != 0) {
            result ^= xor1;
        }
        if (n % 2 != 0) {
            result ^= xor2;
        }
        return result;
    }
};
