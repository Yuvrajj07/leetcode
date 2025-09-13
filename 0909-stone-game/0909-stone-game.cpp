class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<int>& v) {
        if (i > j) return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        int takeStart = v[i] - solve(i + 1, j, v);
        int takeEnd = v[j] - solve(i, j - 1, v);
        dp[i][j] = max(takeStart, takeEnd);
                return dp[i][j];
    }
    
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        dp = vector<vector<int>>(n, vector<int>(n, -1));
        return solve(0, n - 1, piles) > 0;
    }
};