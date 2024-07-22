class Solution {
public:
    vector<vector<int>> generateMatrix(int n1) {
     
        int m= n1;
        int n= n1,p=1;
        int rowst=0,colst=0,rowend=n1-1,colend=n1-1;
        vector<vector<int>> ans(n, vector<int>(n, 0)); 
        while (rowst<=rowend && colst<=colend){
            for (int i =colst;i<=colend;i++){
                ans[rowst][i]=p++;
                
            }
            rowst++;
            for (int i =rowst;i<=rowend;i++){
                ans[i][colend]=p++;
                
            }
            colend--;
             if(rowst<=rowend){
            for (int i =colend;i>=colst;i--){
                ans[rowend][i]=p++;
                
            }
             }
            rowend--;
            if(colst<=colend){
            for (int i =rowend;i>=rowst;i--){
                ans[i][colst]=p++;
                
            }
            }
            colst++;
        }
        return ans;   
    }
};