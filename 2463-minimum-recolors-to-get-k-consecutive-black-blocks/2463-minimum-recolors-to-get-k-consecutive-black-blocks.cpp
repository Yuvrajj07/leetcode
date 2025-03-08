// class Solution {
// public:
//     int minimumRecolors(string s, int k) {
//         int i =0,j=0;
//         int n=s.length(),b=0;
//         int ans =INT_MAX;
//         while(j<n){
//             if (j-i+1==k){
//                 int z= k-b;
//                 ans=min (ans,z);
//                 if (s[i]=='b') b--;
//                 i++;
//             }
//             else {
//                 if (s[]=='B') b++;
//                 j++;
//             }
//         }
//         return ans;
//     }
// };


class Solution {
public:
    int minimumRecolors(string s, int k) {
        int i = 0, j = 0;
        int n = s.length(), b = 0;  // `b` stores the count of 'B' in the current window
        int ans = INT_MAX;

        while (j < n) {
            if (s[j] == 'B') b++;  // Count 'B' in the current window
            if (j - i + 1 == k) {  // When the window size reaches `k`
                int z = k - b; // `z` is the number of 'W' we need to convert
                ans = min(ans, z);
                if (s[i] == 'B') b--; // If `i` is 'B', remove its effect
                i++; // Slide window forward
            }
            j++; // Expand window
        }

        return ans;
    }
};
