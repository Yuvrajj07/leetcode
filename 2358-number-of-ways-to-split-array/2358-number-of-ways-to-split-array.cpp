// class Solution {
// public:
//     int waysToSplitArray(vector<int>& nums) {
//         int n = nums.size();
//         int ans=0,sum=0,ttsum=0;
//         for (auto it :nums){
//             ttsum+=it;
//         }
//         for (int i =0;i<n-1;i++){
//             sum+=nums[i];
//             sum+=nums[i+1];
//             int right_sum = ttsum-sum;
//             if (sum>right_sum ) ans++;
//             sum-=nums[i+1];
//         }

//         return ans;

//     }
// };
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        long long sum = 0, totalSum = 0;

        // Calculate the total sum of the array
        for (auto it : nums) {
            totalSum += it;
        }

        // Iterate through the array to calculate left and right sums
        for (int i = 0; i < n - 1; i++) {
            sum += nums[i]; // Increment left sum
            long long right_sum = totalSum - sum; // Calculate right sum
            if (sum >= right_sum) { // Check the condition
                ans++;
            }
        }

        return ans;
    }
};
