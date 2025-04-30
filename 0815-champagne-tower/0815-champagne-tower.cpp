// class Solution {
// public:
//     double solve(int i ,int cap,int n,vector<double>&dp){
//         int z= i+1;
//         if (i>n) return 0.0;
//         if (dp[i]!=-1.0) return dp[i];
//         if (cap<z) return dp[i]=(double)(cap/z);
//         if (cap>z) return dp[i]=1.0;
//         return dp[i]= solve(i+1,cap-z,n,dp);
//         // return ;
//     }
//     double champagneTower(int poured, int query_row, int query_glass) {
//         vector<double>dp(query_row+1.0);
//         return solve(0,poured,query_row,dp);

//     } 
// };



// class Solution {
// public:
//     double champagneTower(int poured, int query_row, int query_glass) {
//         int level = 0;
//         int used = 0;

//         while (poured >= level + 1) {
//             level++;
//             poured -= level;
//             if (query_row < level) return 1.0; // This row was fully filled
//         }

//         if (query_row > level) return 0.0;  // Not enough poured to reach this row

//         // If it's the current level where poured < glasses in this level
//         return (double)poured / (query_row + 1);
//     }
// };


class Solution {
public:
    double dp[101][101]; // memo table: row and glass max values (constraints: 0 <= query_row, query_glass <= 100)

    double dfs(int row, int glass, int poured) {
        if (row < 0 || glass < 0 || glass > row) return 0.0; // invalid position
        if (row == 0 && glass == 0) return poured; // base case: top glass

        if (dp[row][glass] != -1.0) return dp[row][glass]; // return cached result

        // get overflow from the two glasses above
        double leftOverflow = max(0.0, (dfs(row - 1, glass - 1, poured) - 1.0) / 2.0);
        double rightOverflow = max(0.0, (dfs(row - 1, glass, poured) - 1.0) / 2.0);

        return dp[row][glass] = leftOverflow + rightOverflow;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        // initialize memo table with -1.0
        for (int i = 0; i <= query_row; ++i)
            for (int j = 0; j <= i; ++j)
                dp[i][j] = -1.0;

        return min(1.0, dfs(query_row, query_glass, poured));
    }
};
