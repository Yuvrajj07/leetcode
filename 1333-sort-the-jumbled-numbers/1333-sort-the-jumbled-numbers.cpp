class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> v;
        
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            int ans = 0, multiplier = 1;
            
            // Transform the number using the mapping
            if (x == 0) {
                ans = mapping[0];
            } else {
                while (x > 0) {
                    int z = x % 10;
                    ans = ans + mapping[z] * multiplier;
                    multiplier *= 10;
                    x /= 10;
                }
            }
            
            v.push_back({nums[i], ans});
        }

        // Sort the vector based on the transformed numbers
        sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        // Construct the output vector
        vector<int> op;
        for (const auto &p : v) {
            op.push_back(p.first);
        }
        
        return op;
    }
};












// class Solution {
// public:
// // bool cmp(vector<int,int>v,vector<int,int>v2){
// //                 if (v[0].second>)    
// // }
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         vector<pair<int ,int >>v;
//         for (int i =0;i<nums.size();i++){
//             int x= nums[i];
//             int ans =0;
//             while (x>0){
//                 int z= x%10;
//                 ans=ans*10+mapping[z];
//                 x=x/10;
//             }
//             // cout<<ans<<" ";
//             int rev=0;
//             while (ans>0){
//                 int z= ans%10;
//                 rev=rev*10+z;
//                 ans=ans/10;
//             }
//             cout<<rev<<" ";
//             v.push_back({nums[i],rev});
//         }
//     sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
//         return a.second < b.second;
//     });        
//             vector<int>op;
//             for (int  i=0;i<v.size();i++){
//                 op.push_back(v[i].first);
//             }
        
//         return op;
//     }
// };