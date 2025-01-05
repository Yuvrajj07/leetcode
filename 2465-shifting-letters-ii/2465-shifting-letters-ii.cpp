// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         for (auto it:shifts){
//             int st = it[0];
//             int en = it[1];
//             int op = it[2];
//             for (int i=st;i<=en;i++){
//                 if (op==1){
//                     if (s[i]!='z')
//                     s[i]=s[i]+1;
//                     else s[i]='a';
                
//                 }
//                 else {
//                     if (s[i]!='a')
//                     s[i]=s[i]-1;
//                     else s[i]='z';
               

//                 }

//             }
//         }
//         return s;
//     }
// };

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0); // Difference array to track cumulative shifts

        // Apply the shifts to the difference array
        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int op = shift[2];

            diff[start] += (op == 1 ? 1 : -1);
            diff[end + 1] -= (op == 1 ? 1 : -1);
        }

        // Calculate the cumulative shifts
        int cumulativeShift = 0;
        for (int i = 0; i < n; ++i) {
            cumulativeShift += diff[i];
            int shift = (cumulativeShift % 26 + 26) % 26; // Handle negative shifts and wrap around
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }

        return s;
    }
};
