class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>m;
        for (auto it:s){
            m[it]++;
        }
        int ans=0;
        for (auto it:m){
            if (it.second>2) {
                if (it.second%2==0)
                ans+=2;
                else ans+=1;
            }
            else ans+=it.second;
        }
        return ans;
    }
};