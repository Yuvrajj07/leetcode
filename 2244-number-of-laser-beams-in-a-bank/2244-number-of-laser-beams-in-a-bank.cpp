class Solution {
public:
    int numberOfBeams(vector<string>& b) {
        int  prev=0;
        int ans=0;
        for (int i =0;i<b.size();i++){
            int x=0;
            for (int j=0;j<b[i].size();j++){
                if (b[i][j]=='1') x++;
            }
            if (x>0){
                ans =ans+x*prev;
                prev=x;
            }
        }
        return ans;
        
    }
};