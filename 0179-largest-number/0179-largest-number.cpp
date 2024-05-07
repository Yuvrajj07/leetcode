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










// class Solution {
// public:
//     // Declare the comparison function before using it
//     static bool cmp(string a, string b) {
//         if (a.length() != b.length()) {
//             if (a.length() > b.length()) return false;
//             else return true;
//         } else {
//             if (a > b) return false;
//             else return true;
//         }
//     }
    
//     string largestNumber(vector<int>& v) {
//         sort(v.begin(), v.end(),cmp);
//         string ans="";
//         for (int i = 0; i < v.size(); i++) {
//             cout << v[i] << " ";
//         }

//         return ans;
//     }
// };
