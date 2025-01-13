class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int,int>r;
        unordered_map<int,int>c;
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]==0){
                    r[i]++;
                    c[j]++;
                }
            }
        }
        for (int i=0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
             if(r.find(i)!=r.end()  ||  c.find(j)!=c.end()){
                matrix[i][j]=0;
            }
            }
        }
        // return matrix;
    }

};