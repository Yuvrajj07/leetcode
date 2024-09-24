class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string>s;
        for (int i=1;i<=n;i++){
            string s1=to_string(i);
            s.push_back(s1);
        }
        sort(s.begin(),s.end());
        vector<int>ans;
        for (auto it :s){
            ans.push_back(stoi(it));
        }
        return ans;

    }
};