//................................USING BFS........................
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        if (m == 0 || n == 0) return;

        queue<pair<int, int>> q;

        // Step 1: Mark boundary 'O's and push them into queue
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                board[i][0] = '#';
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = '#';
                q.push({i, n - 1});
            }
        }
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                board[0][j] = '#';
                q.push({0, j});
            }
            if (board[m - 1][j] == 'O') {
                board[m - 1][j] = '#';
                q.push({m - 1, j});
            }
        }

        // Step 2: Perform BFS to mark all safe 'O's
        vector<int> dirX = {1, -1, 0, 0};
        vector<int> dirY = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (int d = 0; d < 4; ++d) {
                int newX = x + dirX[d];
                int newY = y + dirY[d];

                if (newX >= 0 && newX < m && newY >= 0 && newY < n && board[newX][newY] == 'O') {
                    board[newX][newY] = '#';
                    q.push({newX, newY});
                }
            }
        }

        // Step 3: Modify board
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') board[i][j] = 'X';  // Captured region
                if (board[i][j] == '#') board[i][j] = 'O';  // Restore safe region
            }
        }
    }
};




















// //.......................USING DFS........................
// class Solution {
// public:
//     void dfs(vector<vector<char>>& board, int i, int j) {
//         int m = board.size(), n = board[0].size();
//         if (i < 0  || j < 0 || i >= m || j >= n || board[i][j] != 'O') return;

//         // Mark as safe
//         board[i][j] = '#';

//         // Explore all four directions
//         dfs(board, i + 1, j);
//         dfs(board, i - 1, j);
//         dfs(board, i, j + 1);
//         dfs(board, i, j - 1);
//     }

//     void solve(vector<vector<char>>& board) {
//         int m = board.size(), n = board[0].size();
//         if (m == 0 || n == 0) return;

//         // Mark border-connected 'O's
//         for (int i = 0; i < m; ++i) {
//             if (board[i][0] == 'O') dfs(board, i, 0);
//             if (board[i][n - 1] == 'O') dfs(board, i, n - 1);
//         }
//         for (int j = 0; j < n; ++j) {
//             if (board[0][j] == 'O') dfs(board, 0, j);
//             if (board[m - 1][j] == 'O') dfs(board, m - 1, j);
//         }

//         // Update board
//         for (int i = 0; i < m; ++i) {
//             for (int j = 0; j < n; ++j) {
//                 if (board[i][j] == 'O') board[i][j] = 'X';  // Captured region
//                 if (board[i][j] == '#') board[i][j] = 'O';  // Restore safe region
//             }
//         }
//     }
// };