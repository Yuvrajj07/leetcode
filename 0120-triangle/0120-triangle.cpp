class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int a,b;
        a=t.size();
        b=t[a-1].size();
        vector<vector<int>>v(a,vector<int>(b,INT_MAX));
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<t[i].size();j++)
            {
                v[i][j]=t[i][j];
            }
        }
        for(int i=a-2;i>=0;i--)
        {
            for(int j=0;j<t[i].size();j++)
            {
                v[i][j]=v[i][j]+min(v[i+1][j],v[i+1][j+1]);
            }
        }
        return v[0][0];
    }
};