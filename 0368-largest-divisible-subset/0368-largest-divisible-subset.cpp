class Solution {
public:
    // int solve(int s,int n ,vector<int>nums,vector<int>&dp){
    //     if (s==n) return 0;
    //     if (s[i]%s[n-1]==0) return 1+ solve(s,n-1,nums,dp);
    //     else dp[n]=solve(s+1,n,nums,dp);
    // }


//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         sort(nums.begin(),nums.end());
//         vector<int>ans;
//         for (int i=0;i<nums.size();i++){
//             vector<int>v1;
//             int z= nums[i];
//             v1.push_back(z);
//             for (int j=i+1;j<nums.size();j++){
//                 if (nums[j]%z==0){
//                     v1.push_back(nums[j]);
//                     z=nums[j];
//                 }
//             }
//             for (auto it:v1) cout<<it<<" ";
//             cout<<endl;
//             if (ans.size()<v1.size()){
//                 ans.assign(v1.begin(), v1.end());
//             }

//         }
//         return ans;
//     }
vector<int> largestDivisibleSubset(vector<int>& nums) {
    if (nums.empty()) return {};

    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> dp(n, 1); // Length of subset ending at i
    vector<int> prev(n, -1); // Previous index in the subset

    int maxIndex = 0; // Index of the largest element of the max subset

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> result;
    while (maxIndex != -1) {
        result.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}
};
