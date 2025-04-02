class Solution {
public:
    int shortestSubarray(vector<int>& v, int k) {
        int n = v.size();
        deque<int> dq; // For maintaining indices of elements
        vector<long long> prefixSum(n + 1, 0);
        
        // Calculate prefix sums
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + v[i];
        }
        
        int ans = INT_MAX;
        for (int i = 0; i <= n; ++i) {
            // Remove elements from deque where the sum condition is satisfied
            while (!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= k) {
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }
            
            
            // Maintain increasing order in deque
            while (!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
        }
        
        return (ans == INT_MAX) ? -1 : ans;
    }
};



// class Solution {
// public:
//     int shortestSubarray(vector<int>& v, int k) {
//         int i =0,j=0;
//         int sum =0;
//         int mx=*max_element(v.begin(),v.end());
//         if (v.size()==1){
//             if (mx>=k) return 1;
//             else return -1; 
//         } 
//         int ans =INT_MAX;
//         while (j<v.size()){
//             if (j==v.size()-1){
//                 while (i<v.size()){       
//                     if (sum>=k){
//                     ans=min(ans,j-i+1);
//                     i++;
//                 }
//                 else {
//                     break;
//                 }
//             }
//         }
//             if (sum>=k){
//                 ans=min(ans,j-i+1);
//                 i++;
//             }
//             else {
//                 sum+=v[j];
//                 j++;
//             }
//         }
//         if (ans!=INT_MAX) return ans;
//         return -1;
//     }
// };