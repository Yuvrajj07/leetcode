class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (freq[a] == freq[b]) {
                return a > b;
            }
            return freq[a] < freq[b];
        });

        return nums;
    }
};




// class Solution {
// public:
//     vector<int> frequencySort(vector<int>& nums) {
//         map<int,int>m;
//         for (int i =0;i<nums.size();i++){
//             m[nums[i]]++;
//         }
//         vector<int>ans;
//         for (auto it:m){
//             int z= it.second;
//             while(z--)
//             ans.push_back(it.first);
//         }
//         reverse (ans.begin(),ans.end())
//         return ans;
//     }
// };