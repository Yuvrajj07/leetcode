class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& v) {
        int m= v.size();
        int n= v[0].size();
        int rowst=0,colst=0,rowend=m-1,colend=n-1;
        vector<int>ans;
        while (rowst<=rowend && colst<=colend){
            
            for (int i =colst;i<=colend;i++){
                cout<<v[rowst][i];
                ans.push_back(v[rowst][i]);
            }
            rowst++;
            for (int i =rowst;i<=rowend;i++){
                cout<<v[i][colend];
                ans.push_back(v[i][colend]);
            }
            colend--;
             if(rowst<=rowend){
            for (int i =colend;i>=colst;i--){
                cout<<v[rowend][i];
                ans.push_back(v[rowend][i]);

            }
             }
            rowend--;
            if(colst<=colend){
            for (int i =rowend;i>=rowst;i--){
                cout<<v[i][colst];
                ans.push_back(v[i][colst]);
            }
            }
            colst++;
        }
        return ans;
    }
};