//o(n^3)
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>>ans;
//         for (int i =0;i<nums.size()-2;i++){
//             for (int j =i+1;j<nums.size()-1;j++){
//                 for (int k =j+1;k<nums.size();k++){
//                     if (nums[i]+nums[j]+nums[k]==0){
//                         ans.push_back({nums[i],nums[j],nums[k]});
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
    
// };

// applying binary search
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end()); // Sort the input array
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) // Skip duplicates
                continue;
            
            int left = i + 1;
            int right = nums.size() - 1;
            int target = -nums[i];
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates
                    while (left < right && nums[left] == nums[left + 1])
                        ++left;
                    while (left < right && nums[right] == nums[right - 1])
                        --right;
                    
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return result;
    }
};
