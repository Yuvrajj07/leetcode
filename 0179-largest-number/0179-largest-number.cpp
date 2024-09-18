class Solution {
private:
    struct LargerNumberComparator {
        bool operator()(const string& a, const string& b) {
            string s1 = a + b;
            string s2 = b + a;
            return s2 < s1;
        }
    };

public:
    string largestNumber(vector<int>& v) {
        vector<string> ans(v.size());
        for (int i = 0; i < v.size(); i++) {
            ans[i] = to_string(v[i]);
        }
         sort(ans.begin(), ans.end(), LargerNumberComparator());

        // If, after being sorted, the largest number is `0`, the entire number
        // is zero.
        if (ans[0] == "0") {
            return "0";
        }

        string largestNumberStr;
        for (const string& numAsStr : ans) {
            cout<<numAsStr<<"";
            largestNumberStr += numAsStr;
        }

        return largestNumberStr;
    }
};

