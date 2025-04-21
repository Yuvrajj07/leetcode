// class Solution {
// public:
//     int solve(int i, int n, vector<vector<int>>& dp, vector<int>& v, int e) {
//         if (i==n) return 0;
//         if (dp[i][e]!= -1) return dp[i][e];
//         int take=0;
//         if ((v[i]%2==0 && e==1) || (v[i]%2!=0 && e==0)){
//             take =1+solve(i+1,n,dp,v,1-e); 
//         }
//         int ntake =solve(i+1,n,dp,v,e); 
//         return dp[i][e] = max(take,ntake);
//     }

//     int maximumLength(vector<int>& nums) {
//         int n = nums.size();
//         if (n<=2) return n;
//         vector<vector<int>> dp(n+1,vector<int>(2,-1));
//         return max(solve(0,n,dp,nums,0),solve(0,n,dp,nums,1)); 
//     }
// };


class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        int sameParity = max(even, odd);

        // Case 2: All odd sum -> find max alternating subsequence
        int alt1 = 0, alt2 = 0;
        int parity = -1;
        // Start with even
        parity = 0;
        for (int num : nums) {
            if (num % 2 == parity) {
                alt1++;
                parity = 1 - parity;
            }
        }

        // Start with odd
        parity = 1;
        for (int num : nums) {
            if (num % 2 == parity) {
                alt2++;
                parity = 1 - parity;
            }
        }

        int maxAlt = max(alt1, alt2);
        // Final answer is max of both cases
        return max(sameParity, maxAlt);
    }
};
