class Solution {
public:
    bool canArrange(vector<int>& v, int k) {
        // Step 1: Adjust all elements in the array to be in the range [0, k-1]
        for (int i = 0; i < v.size(); i++) {
            v[i] = ((v[i] % k) + k) % k; // This ensures that negative remainders are converted to positive
        }
        
        // Step 2: Count the frequency of each remainder
        unordered_map<int, int> m;
        for (int i = 0; i < v.size(); i++) {
            m[v[i]]++;
        }

        // Step 3: Check if the array can be rearranged
        for (auto it : m) {
            int remainder = it.first;
            int freq = it.second;

            if (remainder == 0) {
                // Special case for remainder 0, it must have an even frequency
                if (freq % 2 != 0) {
                    return false;
                }
            } else {
                int complement = k - remainder;
                // Check if the complement exists with the same frequency
                if (m[complement] != freq) {
                    return false;
                }
            }
        }

        return true;
    }
};


// class Solution {
// public:
//     bool canArrange(vector<int>& v, int k) {
        
//         for (int i =0;i<v.size();i++){
//             v[i]=v[i]%k;
//         }
//         unordered_map<int,int>m;
//         for (int i =0;i<v.size();i++){
//             m[v[i]]++;
//         }
//         for (auto it:m){
//             cout<<it.first<<" "<<it.second<<endl;
//         }
//         for (auto it :m){
//             int z=it.first;
//             if (z==0 ) continue;
//             int x= k-z;
//             if (m.find(x)!=m.end()){
//                 if (it.second!=m[x]) return false;
//             }
//             else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };