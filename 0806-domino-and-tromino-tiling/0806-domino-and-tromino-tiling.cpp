// class Solution {
// public:
//     int numTilings(int n) {
//         const int MOD = 1e9 + 7;
//         if (n <= 1) return 1;
//         if (n == 2) return 2;
//         if (n == 3) return 5;

//         vector<long long> dp(n + 1);
//         dp[0] = 1; dp[1] = 1; dp[2] = 2; dp[3] = 5;

//         for (int i = 4; i <= n; ++i) {
//             dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
//         }

//         return dp[n];
//     }
// };

class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int n, vector<int>& memo) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        if (memo[n] != -1) return memo[n];

        long long ways = (2LL * solve(n - 1, memo) % MOD + solve(n - 3, memo)) % MOD;
        memo[n] = (int)ways;
        return memo[n];
    }

    int numTilings(int n) {
        vector<int> memo(n + 1, -1);
        return solve(n, memo);
    }
};
