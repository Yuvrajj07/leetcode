// class Solution {
// public:
//     bool isv(char c){
//         c=tolower(c);
//         return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
//     }
//     std::string to_lower_str(const std::string &s) {
//     std::string result = s;
//     std::transform(result.begin(), result.end(), result.begin(),
//                    [](unsigned char c){ return std::tolower(c); });
//     return result;
// }
//     vector<string> spellchecker(vector<string>& w, vector<string>& q) {
//         unordered_set<string>s;
//         vector<pair<string ,int>>vow;
//         int p=0;
//         for (auto it :w){
//             s.insert(it);
//             string s1="";
//             for (auto i:it){
//                 if(isv(i)) s1+='_';
//                 else s1+=i;
//             }
//             vow.push_back({s1,p});
//             p++;
//         }
//         vector<string >ans;
//         for (int i =0;i<q.size();i++){
//             string qu=q[i];
//             bool chk=true;
//             if (chk){
//                 for (int j =0;j<w.size();j++){
//                     if (w[j]==qu){
//                         ans.push_back(w[j]);
//                         chk=false;          
//                         break;  
//                     }
//                 } 
//             }
//             if (chk){
//                 for (int j =0;j<w.size();j++){
//                     if (to_lower_str(w[j])==to_lower_str(q[i])){
//                         ans.push_back(w[j]);
//                         chk=false;
//                         break;
//                     }
//                 }
//             }
//             if (chk){
//                 string vn="";
//                 for (int j=0;j<qu.length();j++){
//                     if (isv(qu[j])){
//                         vn=vn+"_";
//                     }
//                     else vn+=qu[j];
//                 }
//                 cout<<vn<<" "<<endl;
//                 for (int j =0;j<vow.size();j++){
//                     cout<<vow[j].first<<" ";
//                     if (vn==vow[j].first){
//                         ans.push_back(w[vow[j].second]);
//                         chk=false;
//                         break;
//                     }
//                 }
//                 cout<<endl;
//             }

//             if (chk){
//                 ans.push_back("");
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    bool isv(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    std::string to_lower_str(const std::string &s) {
        std::string result = s;
        std::transform(result.begin(), result.end(), result.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        return result;
    }

    std::string mask_vowels(const std::string &s) {
        std::string result = "";
        for (char c : s) {
            if (isv(c)) result += '_';
            else result += c;
        }
        return result;
    }

    vector<string> spellchecker(vector<string>& w, vector<string>& q) {
        unordered_set<string> exact_set;
        unordered_map<string, string> case_insensitive_map;
        unordered_map<string, string> vowel_mask_map;

        // Preprocess the wordlist
        for (const string &word : w) {
            exact_set.insert(word);

            string word_lower = to_lower_str(word);
            if (case_insensitive_map.find(word_lower) == case_insensitive_map.end()) {
                case_insensitive_map[word_lower] = word;
            }

            string word_mask = mask_vowels(word_lower);
            if (vowel_mask_map.find(word_mask) == vowel_mask_map.end()) {
                vowel_mask_map[word_mask] = word;
            }
        }

        vector<string> ans;

        // Process each query
        for (const string &qu : q) {
            // Rule 1: Exact match
            if (exact_set.find(qu) != exact_set.end()) {
                ans.push_back(qu);
                continue;
            }

            // Rule 2: Case-insensitive match
            string qu_lower = to_lower_str(qu);
            if (case_insensitive_map.find(qu_lower) != case_insensitive_map.end()) {
                ans.push_back(case_insensitive_map[qu_lower]);
                continue;
            }

            // Rule 3: Vowel error match
            string qu_mask = mask_vowels(qu_lower);
            if (vowel_mask_map.find(qu_mask) != vowel_mask_map.end()) {
                ans.push_back(vowel_mask_map[qu_mask]);
                continue;
            }

            // Rule 4: No match
            ans.push_back("");
        }

        return ans;
    }
};
