class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<int>>v=board;
        
        for (int i=0;i<board.size();i++){
            for (int j =0;j<board[0].size();j++){
                int o=0,z=0;
                for (int i1 = -1; i1 <= 1; ++i1) {         // Row offset: -1, 0, 1
                    for (int j1 = -1; j1 <= 1; ++j1) {     // Column offset: -1, 0, 1
                              if (i1 == 0 && j1 == 0) continue;
                            int newRow =i + i1;
                            int newCol = j + j1;

                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                                 if (v[newRow][newCol]==1){
                                    o++;
                                 }
                                 else z++;
                            }
        }
                }       
                if (o<2 && v[i][j]==1) board[i][j]=0;
                else if ((o==3 || o==2 )&& v[i][j]==1) board[i][j]=1;
                else if (o>3 && v[i][j]==1) board[i][j]=0;
                else if (o==3 && v[i][j]==0 ) board[i][j]=1;
                
                
            }
        }
    }
};