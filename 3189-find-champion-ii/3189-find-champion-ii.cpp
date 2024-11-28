class Solution {
public:
    int findChampion(int n, vector<vector<int>>& v) {
        unordered_set<int>s;
        for (auto it:v){
            int x=it[0];
            int y=it[1];
            s.insert(y);
        }
        int ans =-1;
        for (int i=0;i<n;i++){
            if (s.find(i)==s.end()) ans =i;
        } 
        if(n-s.size()>=2) return -1;
        return ans;
    }
};