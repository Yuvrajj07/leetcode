
class Solution {
public:
    string clearStars(string s) {
        auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first)
                return a.first < b.first;   // Increasing lex order
            return a.second > b.second;     // If same char, use the latest (max index)
        };

        multiset<pair<char, int>, decltype(cmp)> m(cmp);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '*') {
                if (!m.empty()) {
                    // Remove the smallest element
                    auto it = m.begin();
                    s[it->second] = '0';  // Mark as removed
                    m.erase(it);
                }
                s[i] = '0'; // Mark '*' as removed
            } else {
                m.insert({s[i], i});
            }
        }

        string ans = "";
        for (char ch : s) {
            if (ch != '0') ans += ch;
        }
        return ans;
    }
};









