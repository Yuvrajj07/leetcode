

//                       ................. USING  DP BOTTOM-UP APPROACH........................

class Solution {
public:
    int maximizeWin(vector<int>& v, int k) {
        int n = v.size();
        vector<int> dp(n + 1, 0);  // dp[i] stores the max number of elements from [0...i-1]
        int ans = 0, j = 0;

        for (int i = 0; i < n; ++i) {
            while (v[i] - v[j] > k) {
                j++;
            }
            dp[i + 1] = max(dp[i], i - j + 1);  // Update dp for the current segment
            ans = max(ans, dp[j] + (i - j + 1));  // Combine with the best previous segment
        }
        return ans;
    }
};


//.....................USING SLIDING WINDOW --> 53 TESTCASE PASSED.................... 
// class Solution {
// public:
//     int maximizeWin(vector<int>& v, int k) {
//         int ans=0,mx=0;
//         int i =0,j=0,initial=v[0];
//         multiset<int>v1;
//         while (j<v.size()){
//             if (v[j]-initial<=k){
//                 mx=max(mx,j-i+1);
//                 j++;
//                 if (j==v.size()){
//                     v1.insert(mx);
//                 } 
//             }
//             else {
//                 v1.insert(mx);
//                 mx=max(mx,j-i);
//                 while (v[i]==v[i+1] && i<v.size()-1){
//                     i++;
//                 }
//                     i++;
//                     initial=v[i];
//             }
//         }
//         if (v1.size() >= 2) {
//             int largest = *v1.rbegin();        // Get the largest value
//             v1.erase(--v1.end());             // Remove the largest value
//             ans = largest + *v1.rbegin();     // Add the next largest value
//         } else if (!v1.empty()) {
//             // If only one segment exists
//             ans = *v1.rbegin();
//         }
//         if(ans>v.size()) return v.size();
//         return ans;
                
//     }
// };