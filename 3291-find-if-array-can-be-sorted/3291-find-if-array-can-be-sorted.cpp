// class Solution {
// public:
//     bool canSortArray(vector<int>& nums) {
//         vector<int>v;
//         for (int i =0;i<nums.size();i++){
//             v.push_back(nums[i]);
//         }
//         sort(v.begin(),v.end());
//         for (int i =0;i<v.size();i++){
//             int z=__builtin_popcount(nums[i]);
//             int z2=__builtin_popcount(v[i]);
//             if (z!=z2) return false;
            
//         }
//         return true;
//     }
// };



class Solution {
public:
    static bool canSortArray(const vector<int> &nums) {
        const uint8_t n = nums.size();
        uint16_t pmax = 0, cmin = 0, cmax = 0;
        uint8_t pcnt = 0;
        for (const uint16_t v : nums) {
            if (const uint8_t ccnt = popcount(v); pcnt == ccnt) {
                cmin = min(cmin, v);
                cmax = max(cmax, v);
            } else if (cmin < pmax) {
                return false;
            } else {
                pmax = cmax;
                cmin = cmax = v;
                pcnt = ccnt;
            }
        }
        return cmin >= pmax;
    }
};