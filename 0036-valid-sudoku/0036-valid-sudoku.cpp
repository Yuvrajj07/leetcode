class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
      
 for (int i = 0; i < 9; i += 3) {
    // for every 3 X 3 group 
            for (int j = 0; j < 9; j += 3) {
                unordered_map<char, int> subgrid_map;
                for (int row = i; row < i + 3; row++) {
                    for (int col = j; col < j + 3; col++) {
                        if (board[row][col] != '.') {
                            if (subgrid_map[board[row][col]] > 0) {
                                return false;
                            }
                            subgrid_map[board[row][col]]++;
                        }
                    }
                }
            }
        }


        for (int i=0;i<9;i++){
            // for every column:
            unordered_map<char,int>m;
          m[board[0][i]]++;
          m[board[1][i]]++;
          m[board[2][i]]++;
          m[board[3][i]]++;
          m[board[4][i]]++;
          m[board[5][i]]++;
          m[board[6][i]]++;
          m[board[7][i]]++;
          m[board[8][i]]++;
          
            for (auto it:m){
                if (it.first!='.' && it.second>1) return false;
            }
        }
         for (int i=0;i<9;i++){
            // for every row 
            unordered_map<char,int>m;
          m[board[i][0]]++;
          m[board[i][1]]++;
          m[board[i][2]]++;
          m[board[i][3]]++;
          m[board[i][4]]++;
          m[board[i][5]]++;
          m[board[i][6]]++;
          m[board[i][7]]++;
          m[board[i][8]]++;
          
            for (auto it:m){
                if (it.first!='.' && it.second>1) return false;
            }
        }

    return true;
        

    }
};