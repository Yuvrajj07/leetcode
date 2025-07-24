class Solution {
public:
    unordered_set<string>st;
    void solve (int i ,string s,vector<int>&vis,string ans){
            st.insert(ans);
        for (int  j =0;j<s.length();j++){
            if (!vis[j]){
                vis[j]=1;
                ans+=s[j];
                solve(i+1,s,vis,ans);
                ans.pop_back();
                vis[j]=0;

            }
        } 
    }

    int numTilePossibilities(string tiles) {
        vector<int>vis(tiles.length(),0);   
        solve(0,tiles,vis,"");
        return st.size()-1;
    }
};