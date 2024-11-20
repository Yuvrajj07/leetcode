class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> m;
        int n = s.size();

        // Count total occurrences of 'a', 'b', and 'c'
        for (char c : s) m[c]++;
        if (m['a'] < k || m['b'] < k || m['c'] < k) return -1;

        int i = 0, j = 0;
        int ans = n;

        while (j < n) {
            // Decrease the frequency of the current character
            m[s[j]]--;

            // Shrink the window from the left while the condition is violated
            while (i <= j && (m['a'] < k || m['b'] < k || m['c'] < k)) {
                m[s[i]]++;
                i++;
            }

            // Update the minimum length
            ans = min(ans, n - (j - i + 1));
            j++;
        }

        return ans;
    }
};











// class Solution {
// public:
//     int takeCharacters(string s, int k) {
//         unordered_map<char,int>m;
//         int i=0,j=0;
//         int ans =INT_MAX;
//         while (j<s.length()){
//             m[s[j]]++;
//             if(m.size()==3){
//                 if (m['a']>=k && m['b']>=k && m['c']>=k){
//                     while(i<j){
//                         if (m[s[i]]>k) {
//                             m[s[i]]--;
//                             i++;
//                             if (m[s[i]]==0) m.erase(m[s[i]]);
//                         }
//                         else break;
//                     }
                   
//                 }
//                  ans =min(ans,j-i+1);
//                 // i++;
//             }
//             j++;
//         }
//         if (ans !=INT_MIN)  return ans ;
//         return -1;
//     }
// };

