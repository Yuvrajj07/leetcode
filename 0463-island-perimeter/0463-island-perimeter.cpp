
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& v) {
        int ans=0;
        if (v.empty() || v[0].empty()) return 0;
        for (int i =0;i<v.size();i++){
            for (int j=0;j<v[i].size();j++){                
                if (v[i][j]==1){
                    int u=1,d=1,l=1,r=1;
                    if (i>=1 && v[i-1][j]==1){
                        u=0;
                    }
                    if (j>=1 && v[i][j-1]==1){
                        l=0;
                    }
                    if (i + 1 < v.size() && v[i+1][j]==1){
                        d=0;
                    }

                    if (j + 1 < v[i].size() && v[i][j+1]==1){
                        r=0;
                    }
                    ans+=u+d+l+r;
                }
            }
        }
        return ans;
    }
};