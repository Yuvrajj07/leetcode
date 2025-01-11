//.......................\U0001f601\U0001f601 greedy approach......................................

class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int>m;
        for (auto it:s){
            m[it]++;
        }
        int min=1;
        int od=0;
        for (auto it :m){
            if (it.second%2!=0){
                od++;
            }
        }
        if (od!=0)
         min=od;
         if (k>=od && k<=s.length()) return true;
         return false;
    }
};