class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        unordered_map<char, int> bmax;

        // Step 1: Calculate the maximum frequency of each character across all words in words2
        for (const auto& word : words2) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }
            for (const auto& [ch, count] : freq) {
                bmax[ch] = max(bmax[ch], count);
            }
        }

        // Step 2: Check each word in words1
        for (const auto& word : words1) {
            unordered_map<char, int> freq;
            for (char c : word) {
                freq[c]++;
            }

            bool isUniversal = true;
            for (const auto& [ch, count] : bmax) {
                if (freq[ch] < count) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};




// class Solution {
// public:
//     vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
//      vector<string> ans;
//      unordered_map<char,int>m1;
//      for (auto  it :words2){
//         for (int i =0;i<it.length();i++){
//             m1[it[i]]++;
//         }
//      }
//      for (auto it:words1){
//         unordered_map<char,int>m;
//         string s=it;
//         for (int i=0;i<s.length();i++){
//             m[s[i]]++;
//         }
//         unordered_map<char,int>c=m1;
//         int cnt=0;
//         for (auto iit:c){
//             char x=iit.first;
//             int qn= iit.second;
//             if(m.find(x)!=m.end()) cnt++;
//         }
//         if (cnt==m1.size()){
//             ans.push_back(it);
//         }

//     }
//     return ans;   
//     }
// };