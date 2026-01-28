class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n1=edges[0][0],n2=edges[0][1];
        int n3=edges[1][0],n4=edges[1][1];
        if (n1==n3 || n1==n4) return n1;
         return n2;
        
    }
};