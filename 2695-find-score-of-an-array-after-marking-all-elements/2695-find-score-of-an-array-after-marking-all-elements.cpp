class Solution {
public:
    long long findScore(vector<int>& nums) {
        multiset<pair<int, int>> m;
        int n = nums.size();

        // Insert all elements with their indices into the multiset
        for (int i = 0; i < n; i++) {
            m.insert({nums[i], i});
        }

        vector<int> v(n, 0); // To track marked elements
        long long ans = 0;

        while (!m.empty()) {
            // Extract the smallest element from the multiset
            auto it = m.begin();
            int value = it->first;
            int index = it->second;

            // Remove the element from the multiset
            m.erase(it);

            // Skip if already processed
            if (v[index]) continue;

            // Add the value to the score
            ans += value;

            // Mark this element and its neighbors as processed
            v[index] = 1;
            if (index > 0) v[index - 1] = 1;
            if (index < n - 1) v[index + 1] = 1;
        }

        return ans;
    }
};






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

