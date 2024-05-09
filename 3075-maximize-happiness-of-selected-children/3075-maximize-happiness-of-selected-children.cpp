class Solution {
public:
    long long maximumHappinessSum(vector<int>&v, int k) {
        multiset<long long>m;
        for(int i=0;i<v.size();i++){
            m.insert(v[i]);
        }
        long long  ans =0,i=0;
        while (i<k && !m.empty()){
            int x=*m.rbegin()-i;
            if(x<0) x=0;
            ans+=x;
            auto it=*m.begin();
              m.erase(--m.end());
            i++;
        }
        return ans;
        
    }
};

// class Solution {
// public:
//     long long maximumHappinessSum(vector<int>& v, int k) {
//         multiset<int> m(v.begin(), v.end());

//         long long ans = 0;
//         int i = 0;
//         while (i < k && !m.empty()) { // Add check to avoid accessing out-of-bounds
//             int x = *m.rbegin() - i;
//             if (x < 0) x = 0;
//             ans += x;
//             m.erase(--m.end()); 
//             i++;
//         }
//         return ans;
//     }
// };
