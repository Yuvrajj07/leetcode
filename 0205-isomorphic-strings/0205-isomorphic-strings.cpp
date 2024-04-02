// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         int x = s.length();
//         int y = t.length();
//         if (x==y){
//              unordered_map<int,int>m1;
//              unordered_map<int,int>m2;
//             for (int i=0;i<t.length();i++){
//                  m2[t[i]]++;
//                  m1[s[i]]++;
//                 if (m1.size()!=m2.size() || m2[t[i]]!=m1[s[i]]) return false;
//              }
//             return true;
//         }
//         return false ;
//     }
// };


#include <string>
#include <unordered_map>

class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        int x = s.length();
        int y = t.length();
        if (x != y)
            return false;

        unordered_map<char, char> m1;
        unordered_map<char, char> m2;

        for (int i = 0; i < x; ++i) {
            // Check mapping from s to t
            if (m1.find(s[i]) == m1.end())
                m1[s[i]] = t[i];
            else if (m1[s[i]] != t[i])
                return false;

            // Check mapping from t to s
            if (m2.find(t[i]) == m2.end())
                m2[t[i]] = s[i];
            else if (m2[t[i]] != s[i])
                return false;
        }

        return true;
    }
};
