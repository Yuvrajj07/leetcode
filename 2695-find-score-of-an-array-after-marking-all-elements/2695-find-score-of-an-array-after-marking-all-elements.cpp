#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> processed(n, 0); // To track processed elements
        long long ans = 0;

        // Min-heap to store {value, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Push all elements with their indices into the heap
        for (int i = 0; i < n; i++) {
            minHeap.push({nums[i], i});
        }

        // Process elements in order of smallest value
        while (!minHeap.empty()) {
            auto [value, index] = minHeap.top();
            minHeap.pop();

            // If this element is already processed, skip it
            if (processed[index]) continue;

            // Add value to the score
            ans += value;

            // Mark this element as processed
            processed[index] = 1;

            // Mark adjacent elements as processed if within bounds
            if (index > 0) processed[index - 1] = 1;
            if (index < n - 1) processed[index + 1] = 1;
        }

        return ans;
    }
};









// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         multiset<int> m(nums.begin(), nums.end());
//         vector<int> v(nums.size(), 0); // To track marked elements
//         long long ans = 0;

//         while (!m.empty()) {
//             int x = *m.begin(); // Get the smallest element
//             ans += x;

//             for (int i = 0; i < nums.size(); i++) {
//                 if (nums[i] == x && v[i] == 0) { // Process unmarked element
//                     m.erase(m.begin()); // Remove the smallest element
//                     v[i] = 1; // Mark the current element

//                     // Mark and remove the previous element if unmarked
//                     if (i >= 1 && v[i - 1] == 0) {
//                         int del1 = nums[i - 1];
//                         auto it = m.find(del1);
//                         if (it != m.end()) {
//                             m.erase(it);
//                         }
//                         v[i - 1] = 1;
//                     }

//                     // Mark and remove the next element if unmarked
//                     if (i < nums.size() - 1 && v[i + 1] == 0) {
//                         int del2 = nums[i + 1];
//                         auto it = m.find(del2);
//                         if (it != m.end()) {
//                             m.erase(it);
//                         }
//                         v[i + 1] = 1;
//                     }

//                     break; // Stop searching for `x` in nums
//                 }
//             }

//             // Check if all elements are processed
//             if (accumulate(v.begin(), v.end(), 0) == nums.size()) {
//                 break;
//             }
//         }

//         return ans;
//     }
// };







// class Solution {
// public:
//     long long findScore(vector<int>& nums) {
//         multiset<int>m(nums.begin(),nums.end());
//         vector<int>v(nums.size(),0);
//         long long ans=0;
//         while (!m.empty()){
//             int x= *m.begin();
//               ans+=x;
//             for (int i=0;i<nums.size();i++){
//                 if (nums[i]==x){
//                     m.erase(m.begin());
//                     v[i]=1;
//                     if (i>=1 && v[i-1]==0){
//                         int del1=nums[i-1];
//                         auto it=m.find(del1);
//                         if (it!=m.end()){
//                             m.erase(it);
//                         }
//                            v[i-1]=1;
                           
//                     }
//                      if (i<nums.size()-1 && v[i+1]==0){
//                         int del2= nums[i+1];
//                         auto it=m.find(del2);
//                         if (it!=m.end()){
//                             m.erase(it);
//                         }
//                         v[i+1]=1;  
//                      }
//                     //  cout<<x<<" ";
                     
//                      break;
//                 }


                
//             }
//             int tt=accumulate(v.begin(),v.end(),0);
//             if (tt==v.size()) break;
            
//         }
//         return ans;
//     }
// };

