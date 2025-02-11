// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         bool chk= s.find(part);
//             for (int i =0;i<=s.length()-part.length();i++){
//                 string s1=s.substr(i,part.length());
//                 if (s1==part){
//                     string p1=s.substr(0,i);
//                     string p2=s.substr(i+part.length());
//                     s=p1+p2;
//                     i=-1;
//                 }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         for (int i = 0; i <= s.length() - part.length(); i++) {
//             string s1 = s.substr(i, part.length());  
//             if (s1 == part) { 
//                 string p1 = s.substr(0, i); 
//                 string p2 = s.substr(i + part.length());  
//                 s = p1 + p2;  
//                 i = -1;  
//             }
//         }
//         return s;  
//     }
// };
