class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& w, vector<int>& g) {
        vector<string>ans;
        int n =w.size(),curr=-1;
        for (int i =0;i<n;i++){
            if (g[i]!=curr){
                ans.push_back(w[i]);
                curr=g[i];
            }
        }
        return ans;
    }
};