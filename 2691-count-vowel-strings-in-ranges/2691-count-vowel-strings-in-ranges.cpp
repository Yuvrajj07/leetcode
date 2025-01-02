class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        unordered_map<int, int> m;
        int c = 0;
        for (int i = 0; i < words.size(); i++) {
            string s1 = words[i];
            int z = s1.size();
            if ((s1[0] == 'a' || s1[0] == 'e' || s1[0] == 'i' || s1[0] == 'o' || s1[0] == 'u') &&
                (s1[z - 1] == 'a' || s1[z - 1] == 'e' || s1[z - 1] == 'i' || s1[z - 1] == 'o' || s1[z - 1] == 'u')) {
                c++;
            }
            m[i] = c;
        }
        vector<int> ans;
        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];

            int elm_left = (l > 0 ? m[l - 1] : 0); // Cumulative count before index l
            int elm_right = m[r];                // Cumulative count up to index r

            int result = elm_right - elm_left;   // Count of vowel strings in range [l, r]
            ans.push_back(result);
        }
        return ans;
    }
};














// class Solution {
// public:
//     vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
//         unordered_map<int ,int >m;
//         int c=0;
//         for (int i =0;i<words.size();i++){
//             string s1=words[i];
//             int z= s1.size();
//             if ((s1[0]=='a' || s1[0]=='e' || s1[0]=='i' || s1[0]=='o' || s1[0]=='u')&&
//                 (s1[z-1]=='a' || s1[z-1]=='e' || s1[z-1]=='i' || s1[z-1]=='o' || s1[z-1]=='u')){
//                     c++;
//                 }
//                     m[i]=c;
                
//         }
//         vector<int>ans;
//         for (auto it :queries){
//             int r=it[1];
//             int l=it[0];
//             int elm_left=0,elm_right=0;
//             if(l==r){
//                 if(m[l]>m[l-1]){
//                     ans.push_back(1);
//                 }
//                 else {
//                     ans.push_back(0);
//                 }
//             }
//             else {
//             if (l==0){
//                 elm_left=0;
//             }
//             else {
//                 elm_left=m[l];
//             }
//             // if (r==m.size()-1){
//             //     elm_left=m[m.size()-1];
//             // }
//             // else {
//             //     elm_left=m[r+1]-m[r];
//             // }
//             cout<<" --> "<<elm_left<<" m[r] --> "<<m[r]<<endl;
//             int pu=m[r]-elm_left;
//             ans.push_back(pu);
//             }
//         }
//         return ans;
//     }
// };







