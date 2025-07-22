class Solution {
public:
    vector<string>ans;
    void solve (int n,vector<char>&v,string s,char prev){
        if (s.length()==n){
            ans.push_back(s);
            return ;
        }
        for (int i =0;i<=2;i++){
            if (prev!=v[i]){
                s.push_back(v[i]);
                solve(n,v,s,v[i]);
                s.pop_back();
            }
        }
    }
    string getHappyString(int n, int k) {
        vector<char>c={'a','b','c'};
        solve(n,c,"",' ');
        if (ans.size()<k) return "";
        return ans[k-1];         
    }
};