class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> m;
        vector<string> result;
        int x = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == ' ') {
                string s = s1.substr(x, i - x); 
                m[s]++;
                x = i + 1;
            }
        }
        string s = s1.substr(x, s1.length() - x);
        if (!s.empty()) m[s]++;
        x = 0;
        for (int i = 0; i < s2.length(); i++) {
            if (s2[i] == ' ') {
                string s = s2.substr(x, i - x); 
                m[s]++;
                x = i + 1;
            }
        }
        s = s2.substr(x, s2.length() - x);
        if (!s.empty()) m[s]++;
        for (auto it : m) {
            if (it.second == 1) {
                result.push_back(it.first);
            }
        }
        return result;
    }
};











// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         unordered_map<string,int>m;
//         int x=0;
//         vector<string>v;
//         vector<string>v1;
//         for (int i =0;i<s1.length();i++){
//             if(s1[i]==' '){
//                 string s=s1.substr(x,i-x);
//                 m[s]++;
//                 v1.push_back(s);
//                 x=i+1;
//             }
//         }   
//         if (s1[s1.length()]!=' '){
//             string s=s1.substr(x,s1.length()-x);
//             v1.push_back(s1.substr(x,s1.length()-x));
//         }
//          x=0;
//         for (int i =0;i<s2.length();i++){
//             if(s2[i]==' '){
//                 string s=s2.substr(x,i-x);
//                 v1.push_back(s);
//                 m[s]++;
//                 x=i+1;
//             }
//         }
//         if (s2[s2.length()]!=' '){
//             string s=s2.substr(x,s2.length()-x);
//             m[s]++;
//             v1.push_back(s2.substr(x,s2.length()-x));
//         }
//         for (auto it:v1){
//                 m[it]++;
//         }
//         for (auto it:m){
//             if (it.second==1){
//                 v.push_back(it.first);
//             }
//         }
//         return v;

//     }
// };