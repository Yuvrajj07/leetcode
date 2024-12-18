class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string result;
        int currentCharIndex = 25;  // Start from the largest character
        while (currentCharIndex >= 0) {
            if (freq[currentCharIndex] == 0) {
                currentCharIndex--;
                continue;
            }

            int use = min(freq[currentCharIndex], repeatLimit);
            result.append(use, 'a' + currentCharIndex);
            freq[currentCharIndex] -= use;

            if (freq[currentCharIndex] >
                0) {  // Need to add a smaller character
                int smallerCharIndex = currentCharIndex - 1;
                while (smallerCharIndex >= 0 && freq[smallerCharIndex] == 0) {
                    smallerCharIndex--;
                }
                if (smallerCharIndex < 0) {
                    break;
                }
                result.push_back('a' + smallerCharIndex);
                freq[smallerCharIndex]--;
            }
        }

        return result;
    }
};





// class Solution {
// public:
//     string repeatLimitedString(string s, int rp) {
//         multiset<char>m;
//         for (int i =0;i<s.length();i++){
//             m.insert(s[i]);
//         }
//         string ans="";
//         int sn=0;
//         char prev=*m.rbegin();
//         while (!m.empty()){
            
//             if (sn<=rp){
//                 ans+=*m.rbegin();
//                 if (*m.rbegin()==prev){
//                     sn++;
//                 }
//                 else {
//                     sn=1;
//                     prev=*m.rbegin();
//                 }
//                 m.erase(--m.end());
//             }
//             else {
//                 cout<<"else executed"<<endl;
//                 auto it =m.end();
//                 --it;
//                 --it;
//                 ans+=(*it);
//                 sn=1;
//                 prev=*it;
//                 m.erase(it);
//             }
//         if (prev==*m.begin() && *m.begin()==*m.rbegin() && sn>rp){
//             return ans;
//         }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     string repeatLimitedString(string s, int rp) {
//         map<char, int> freq;
//         for (char c : s) {
//             freq[c]++;
//         }

//         string ans = "";
//         int sn = 0;          // Current streak count
//         char prev = '\0';    // Last added character

//         while (!freq.empty()) {
//             auto it = freq.rbegin(); // Get the largest character
//             char cur = it->first;

//             if (cur == prev && sn >= rp) {
//                 // If we've reached the limit for this character
//                 auto nextIt = next(it);
//                 if (nextIt == freq.rend()) {
//                     // If no smaller character is available, stop
//                     break;
//                 }
//                 char nextChar = nextIt->first;
//                 ans += nextChar;
//                 prev = nextChar;
//                 sn = 1;

//                 // Decrease its frequency
//                 if (--freq[nextChar] == 0) {
//                     freq.erase(nextChar);
//                 }
//             }
//              else {
//                 ans += cur;
//                 prev = cur;
//                 sn = (cur == prev) ? sn + 1 : 1;
//                 if (--freq[cur] == 0) {
//                     freq.erase(cur);
//                 }
//             }
//         }

//         return ans;
//     }
// };


// class Solution {
// public:
//     string repeatLimitedString(string s, int rp) {
//         multiset<char> m(s.begin(), s.end()); // Initialize multiset with string
//         string ans = "";
//         int streak = 0; // Current streak count
//         char prev = '\0'; // Previous character added to the result

//         while (!m.empty()) {
//             auto largest = m.rbegin(); // Iterator to the largest element
//             char cur = *largest;

//             if (cur == prev && streak >= rp) {
//                 auto it = m.end();
//                 --it; // Largest element
//                 if (it == m.begin()) {
//                     // No smaller character available, break and return the current result
//                     break;
//                 }
//                 --it; // Second largest character

//                 char nextChar = *it;
//                 ans += nextChar;
//                 streak = 1; // Reset streak for this character
//                 prev = nextChar;

//                 // Remove this character from the multiset
//                 m.erase(m.find(nextChar));
//             }
//              else {
//                 ans += cur;
//                 streak = (cur == prev) ? streak + 1 : 1;
//                 prev = cur;
//                 m.erase(--m.end());
//             }
//         }

//         return ans;
//     }
// };
