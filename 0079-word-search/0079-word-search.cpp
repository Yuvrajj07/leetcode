// class Solution {
// public:
//     bool exist(vector<vector<char>>& board, string word) {
//         int x = word.length();
//         vector<char>ans;
//         for (int i =0;i<board.size();i++){
//             string s=board[i];
//             for (int j=0;j<s.length();j++){
//                 ans.push_back(s[j]);
//             }
//         }
//         bool chk=false;
//         for (int i =0;i<word.length();i++){
//             for (int j =0;j<ans.size();j++){
//                 if (word[i]==ans[j]){
//                     chk=true;
//                     break;
//                 }
//                 else {
//                     chk=false;
//                 }
//             }
//         }
//         return chk;
//         }
    
// };

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();
        
        // Create a visited array to mark visited cells
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        
        // Loop through each cell in the board
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // If the current cell matches the first character of the word,
                // start the DFS search
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int index, vector<vector<bool>>& visited) {
        // If the entire word has been found, return true
        if (index == word.length()) {
            return true;
        }
        
        // Check if the current cell is out of bounds or has already been visited or does not match the current character in word
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index]) {
            return false;
        }
        
        // Mark the current cell as visited
        visited[i][j] = true;
        
        // Check adjacent cells in all four directions
        bool found = dfs(board, word, i + 1, j, index + 1, visited) ||
                     dfs(board, word, i - 1, j, index + 1, visited) ||
                     dfs(board, word, i, j + 1, index + 1, visited) ||
                     dfs(board, word, i, j - 1, index + 1, visited);
        
        // Mark the current cell as unvisited (backtrack)
        visited[i][j] = false;
        
        return found;
    }
};
