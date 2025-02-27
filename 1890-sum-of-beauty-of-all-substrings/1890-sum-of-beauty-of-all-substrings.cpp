// class Solution {
// public:
//     int beautySum(string s) {
//         int ans=0;
//         for (int i =0;i<s.length();i++){
//         unordered_map<char,int>m;
//             m[s[i]]++;
//             for (int j=i+1;j<s.size();j++){
//                 m[s[j]]++;
//                 int mx=INT_MIN,mn=INT_MAX;
//                 for (auto it:m){
//                     mx=max(mx,it.second);
//                     mn=min(mn,it.second);
//                 }
//                 ans+=(mx-mn);
//                 cout<<ans<<endl;
//             }
//         }
//         return ans;
//     }
// };






class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            int mx = 0, mn = INT_MAX;

            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                mx = max(mx, freq[s[j] - 'a']);  // Update max frequency
                
                // Find min frequency > 0 dynamically
                mn = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) mn = min(mn, freq[k]);
                }
                
                ans += (mx - mn);
            }
        }
        return ans;
    }
};
