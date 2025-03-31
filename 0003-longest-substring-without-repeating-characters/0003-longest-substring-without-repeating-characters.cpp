class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int i = 0, ans = 0;

        for (int j = 0; j < s.length(); j++) {
            if (m.find(s[j]) != m.end()) {
                // Move 'i' to the next position after the last occurrence of s[j]
                i = max(i, m[s[j]] + 1);
            }
            m[s[j]] = j; // Update last index of s[j]
            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
