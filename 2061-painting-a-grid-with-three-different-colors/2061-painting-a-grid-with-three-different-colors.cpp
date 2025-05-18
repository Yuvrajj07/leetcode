//....................COPIED .........................

class Solution {
public:
    bool comparePattern(vector<int> pattern1, vector<int> pattern2){
        for(int i = 0; i < pattern1.size(); i++) {
            if(pattern1[i] == pattern2[i]) {
                return false;
            }
        }
        return true;
    }

    void goodCols(int m, int color, vector<int>& curr, vector<vector<int>>& good) {
        if(m <= 1) {
            curr.push_back(color);
            good.push_back(curr);
            curr.pop_back();
            return;
        }
        curr.push_back(color);
        for(int i = 0; i < 3; i++) {
            if(i != color) {
                goodCols(m-1, i, curr, good);
            }
        }
        curr.pop_back();
    } 

    int colorTheGrid(int m, int n) {
        int mod = 1e9+7;

        // Step 1: Generate all valid vertical column patterns
        vector<vector<int>> good;
        vector<int> curr;
        goodCols(m, 0, curr, good);
        goodCols(m, 1, curr, good);
        goodCols(m, 2, curr, good);
        
        int gsize = good.size();
        
        // Step 2: Build a compatibility list of column patterns
        vector<vector<int>> compatible(gsize);
        vector<vector<int>> dp(n, vector<int>(gsize, 0));
       
        for(int i = 0; i < gsize; i++) {
            for(int j = 0; j < gsize; j++) {
                if(comparePattern(good[i], good[j])) {
                    compatible[i].push_back(j);
                }
            }
        }

        // Step 3: Initialize first column
        for(int i = 0; i < gsize; i++) {
            dp[0][i] = 1;
        }

        // Step 4: Fill DP table
        for(int col = 1; col < n; col++) {
            for(int i = 0; i < gsize; i++) {
                for(int j = 0; j < compatible[i].size(); j++) {
                    dp[col][i] = (dp[col][i] + dp[col-1][compatible[i][j]]) % mod;
                }
            }
        }

        // Step 5: Sum the last column's values
        int total_ways = 0;
        for(int i = 0; i < gsize; i++) {
            total_ways = (total_ways + dp[n-1][i]) % mod;
        }

        return total_ways;
    }
};