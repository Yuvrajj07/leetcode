class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int>m;
        for (char c : order) {
            m[c] = 0;
        }
        
        for (char c : s) {
            if (m.find(c) != m.end()) {
                m[c]++;
            }
        }
        
        string ans;
        for (char c : order) {
            ans.append(m[c], c);
        }
        
        for (char c : s) {
            if (m.find(c) == m.end()) {
                ans.push_back(c);
            }
        }
        
        return ans;
    }
};