class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> X(x), N(n-1), ans;
        int j = 0; // Track bits in N

        for (int i = 0; i < 56; i++) {
            if (X[i]) {        // If bit in X is 1
                ans[i] = 1;    // Set ans[i] to 1
            } else {           // Otherwise, use bit from N
                ans[i] = N[j++];
            }
        }

        return ans.to_ullong();
    }
};


// class Solution {
// public:
//     long long minEnd(int n, int x) {
//         int ans =0;
//         for (int i=0;i<n;i++){
//             ans=ans|(i+1);
//         }
//         return ans;
//     }
// };