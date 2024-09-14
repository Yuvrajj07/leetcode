class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        for (char it : s) {
            if (isalpha(it) ||  it<=57 &&it>=48) {
                s1 += tolower(it);
            }
        }
        return solve(s1, 0, s1.length() - 1);
    }

private:
    bool solve(const string& s1, int start, int end) {
        if (start >= end) {
            return true;
        }
        if (s1[start] != s1[end]) {
            return false;
        }
        return solve(s1, start + 1, end - 1);
    }
};