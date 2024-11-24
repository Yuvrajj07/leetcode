class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
     long long   ans =0,sum =0;
     int mn=INT_MAX;
        for (int i =0;i<matrix.size();i++){
            for (int j=0;j<matrix[0].size();j++){
                if (matrix[i][j]<0) ans++;
                mn=min(mn,abs(matrix[i][j]));
                sum+=abs(matrix[i][j]);
            }
        }
        cout<<mn<<endl;
        if (ans%2==0) return sum;
        else return sum-2*mn;
    }
};