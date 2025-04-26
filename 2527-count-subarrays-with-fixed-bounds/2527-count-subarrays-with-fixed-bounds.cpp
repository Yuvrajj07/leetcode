// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         multiset<int>m;
//         int n= nums.size(),ans=0;
//         for (int i =0;i<n;i++){
//             if (nums[i]>=minK && nums[i]<=maxK)
//                 m.insert(nums[i]);
//             else m.clear();

//             if (*m.begin()==minK && *m.rbegin()==maxK){
//                 ans++;
//                 for (int j=i+1;j<n;j++){
//                     if (nums[j]>=minK && nums[j]<=maxK){
//                         ans++;
//                    }
//                    else {
//                     m.erase(nums[i]);
//                     break;
//                    }
//                 }
//             }   
//         }
//         return ans;

//     }
// };

// class Solution {
// public:
//     long long countSubarrays(vector<int>& nums, int minK, int maxK) {
//         long long ans = 0;
//         int n = nums.size();
        
//         for (int start = 0; start < n; start++) {
//             multiset<int> m;
//             for (int end = start; end < n; end++) {
//                 if (nums[end] < minK || nums[end] > maxK) {
//                     break;
//                 }
//                 m.insert(nums[end]);
//                 if (*m.begin() == minK && *m.rbegin() == maxK) {
//                     ans++;
//                 }
//             }
//         }
        
//         return ans;
//     }
// };



    //................................. COPIED.............................

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int minPos = -1, maxPos = -1, badPos = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] < minK || nums[i] > maxK) {
                badPos = i;
            }
            if (nums[i] == minK) {
                minPos = i;
            }
            if (nums[i] == maxK) {
                maxPos = i;
            }
            ans += max(0, min(minPos, maxPos) - badPos);
        }
        return ans;
    }
};

