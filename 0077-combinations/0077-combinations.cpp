class Solution {
public:
    vector<int>t;
    void solve(int i,int n,int k,vector<vector<int>>&ans){
        if (t.size()==k) {
            ans.push_back(t);
            return ;
        }
        if(i>n) return ;        
        t.push_back(i);
        solve(i+1,n,k,ans);
        t.pop_back();
        solve(i+1,n,k,ans);

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        solve(1,n,k,ans);
        return ans;
    }
};