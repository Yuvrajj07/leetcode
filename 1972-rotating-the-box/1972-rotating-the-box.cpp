class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        // Step 1: Simulate gravity for each row
        for (int i = 0; i < box.size(); i++) {
            int empty = box[i].size() - 1; // Position of the farthest empty cell
            for (int j = box[i].size() - 1; j >= 0; j--) {
                if (box[i][j] == '#') {
                    // Move the stone to the farthest empty position
                    swap(box[i][j], box[i][empty]);
                    empty--; // Update the empty position
                } else if (box[i][j] == '*') {
                    // Reset empty position when encountering an obstacle
                    empty = j - 1;
                }
            }
        }

        // Step 2: Rotate the matrix 90 degrees clockwise
        int m = box.size();    // Number of rows in the original matrix
        int n = box[0].size(); // Number of columns in the original matrix
        vector<vector<char>> rotated(n, vector<char>(m)); // Rotated matrix (n x m)

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                rotated[j][m - 1 - i] = box[i][j]; // Rotate 90 degrees clockwise
            }
        }

        return rotated;
    }
};



// class Solution {
// public:
//     vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
//         for (int i=0;i<box.size();i++){
//             for (int j=box[i].size()-1;j>=0;j--){
//                 if(box[i][j]=='#'){
//                     for (int x=j;x<box[i].size();x++){
//                         if (box[i][x]=='.'){
//                             swap(box[i][j],box[i][x]);
                          
//                         }
//                         else if (box[i][x]=='*'){
//                             break;
//                         }
//                     }
//                 }
//             }
//         }
//          int m = box.size();    // Number of rows in the original matrix
//         int n = box[0].size(); // Number of columns in the original matrix
//         vector<vector<char>> rotated(n, vector<char>(m)); // Rotated matrix (n x m)

//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 rotated[j][m - 1 - i] = box[i][j]; // Rotate 90 degrees clockwise
//             }
//         }

//         return rotated;
        

//     }
// };