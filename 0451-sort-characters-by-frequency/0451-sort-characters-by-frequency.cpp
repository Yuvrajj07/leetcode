class Solution {
public:

    // static bool cmp(pair<char,int>a,pair<char,int>b){
    //     if (a.second<b.second) return false;
    //     return true;
    // }
    static bool cmp(pair<char, int> a, pair<char, int> b) {
        if (a.second == b.second) 
            return a.first < b.first; // Maintain order by character (optional)
        return a.second > b.second;   // Sort by frequency in descending order
        }
    string frequencySort(string s) {
        unordered_map<int,int>m;
        vector<pair<char,int>>v;
        for (int i =0;i<s.length();i++){
            m[s[i]]++;
        }
        for (auto it:m){
            v.push_back({it.first,it.second});
        }
        sort(v.begin(),v.end(),cmp);
        string ans="";
        for (auto it :v){
             ans.append(it.second, it.first);
        }
        cout<<endl;
        return ans;
    }
};