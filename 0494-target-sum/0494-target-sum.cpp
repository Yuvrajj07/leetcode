// class Solution {
// public:
//     int  ans=0;
//     int findTargetSumWays(vector<int>& nums, int target) {
//         calc(nums,0,0,target);
//         return ans;
//     }
//     private:
//     void calc(vector<int>v,int sum ,int idx,int target){
//         vector<int>dp(v.size()+1,-1);
//         if (dp[idx]!=-1) return dp[idx];
//         if (idx==v.size()){
//             if (target==sum ) ans++;
//         }
//         else {
//             calc(v,sum+v[idx],idx+1,target);
//             calc(v,sum-v[idx],idx+1,target);
//             dp[idx]=sum;
//         }
//     }
// };


// class Solution {
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         unordered_map<string, int> memo; // Memoization to store intermediate results
//         return calc(nums, 0, 0, target, memo);
//     }
// private:
//     int calc(vector<int>& nums, int sum, int idx, int target, unordered_map<string, int>& memo) {
//         if (idx == nums.size()) {
//             return (sum == target) ? 1 : 0;
//         }

//         // Create a unique key for the current state
//         string key = to_string(idx) + "," + to_string(sum);

//         // Check if the result for this state is already computed
//         if (memo.find(key) != memo.end()) {
//             return memo[key];
//         }

//         // Recursive cases: Add and subtract the current number
//         int add = calc(nums, sum + nums[idx], idx + 1, target, memo);
//         int subtract = calc(nums, sum - nums[idx], idx + 1, target, memo);

//         // Store the result in the memo table
//         memo[key] = add + subtract;
//         return memo[key];
//     }
// };

class Solution {
public:
    int totalSum;

    int findTargetSumWays(vector<int>& nums, int target) {
        totalSum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<int>> memo(nums.size(), vector<int>(2 * totalSum + 1, numeric_limits<int>::min()));
        return calculateWays(nums, 0, 0, target, memo);
    }

    int calculateWays(vector<int>& nums, int currentIndex, int currentSum,
                      int target, vector<vector<int>>& memo) {
        if (currentIndex == nums.size()) {
            // Check if the current sum matches the target
            if (currentSum == target) {
                return 1;
            } else {
                return 0;
            }
        } else {
            // Check if the result is already computed
            if (memo[currentIndex][currentSum + totalSum] !=
                numeric_limits<int>::min()) {
                return memo[currentIndex][currentSum + totalSum];
            }
            // Calculate ways by adding the current number
            int add =
                calculateWays(nums, currentIndex + 1,
                              currentSum + nums[currentIndex], target, memo);

            // Calculate ways by subtracting the current number
            int subtract =
                calculateWays(nums, currentIndex + 1,
                              currentSum - nums[currentIndex], target, memo);

            // Store the result in memoization table
            memo[currentIndex][currentSum + totalSum] = add + subtract;

            return memo[currentIndex][currentSum + totalSum];
        }
    }
};