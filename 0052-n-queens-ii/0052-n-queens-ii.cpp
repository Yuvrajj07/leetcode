class Solution {
public:
  bool issafe(int row, int col, vector<string>& board, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

    void solve (int col,vector<vector<string>>&ans,vector<string>&temp,int n){
        if (col==n){
            ans.push_back(temp);
            return ;
        }
        for (int i =0;i<n;i++){
            if (issafe(col,i,temp,n)){
                temp[col][i]='Q';
                solve(col+1,ans,temp,n);
                temp[col][i]='.';
            }

        }
    }

    int totalNQueens(int n) {
           vector<vector<string>>ans;
        string s(n, '.');
        vector<string> temp(n, s);
        solve(0,ans,temp,n);
        return ans.size();
        
    }
};