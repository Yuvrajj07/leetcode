// class Solution {
// public:
//    string clearStars(string s) {
//         int  c=0,pos1=-1;
//         for (int i =0;i<s.length();i++){
//             if (s[i]=='*'){
//                 c++;
//                 pos1=i;
//             }
//         }
//         auto cmp = [](const pair<char, int>& a, const pair<char, int>& b) {
//             if (a.first != b.first)
//                 return a.first < b.first;   // Increasing order of char
//             return a.second > b.second;     // Decreasing order of int
//         };
//         multiset<pair<char, int>, decltype(cmp)> m(cmp);
//         for (int i =0;i<pos1;i++){
//             if(s[i]!='*')
//             m.insert({s[i],i});
//             if (m.size()>c){
//                 m.erase(--m.end());
//             }
//         }
//         for (auto it:m){
//             int x=it.second;
//             s[x]='0'; 
//         }
//         string ans="";
//         for (int i =0;i<s.length();i++){
//             if (s[i]!='0' && s[i]!='*') ans+=s[i];
//         }
//         return ans;
//     }
// };

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
