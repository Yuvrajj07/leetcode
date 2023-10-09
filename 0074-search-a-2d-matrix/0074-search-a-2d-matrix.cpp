class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int n = m.size();
        int z = m[0].size();
        bool flag =0;
        for (int  i=0;i<n;i++){
            for(int j =0;j<z;j++){
                if (m[i][j]==target)  flag = true;
            }
        }
        return flag ;
    }
};