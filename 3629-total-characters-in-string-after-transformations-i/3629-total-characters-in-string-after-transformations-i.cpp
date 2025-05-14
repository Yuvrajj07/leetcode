// class Solution {
// public:
//     int lengthAfterTransformations(string s, int t) {
//         int n=s.length();
//         for (int i =0;i<t;i++){
//             for (int j =0;j<s.length();j++){
//                 char c=s[j];
//                 s.erase(s.begin()+j,s.begin()+j+1);
//                 if (c=='z') {
//                     s.push_back('a');
//                     s.push_back('b');
//                 }
//                 else {
//                     c++;
//                     s.push_back(c);
//                 }
//             }

//         }
//         cout<<s<<endl;
//         return s.length();
//     }

// };


class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int>v(26,0);
        for(int i=0;i<s.length();i++){
            int x= s[i]-'a';
            v[x]++;
        }
        int mod=1e9+7;
        while (t--){
            int prev=0,z=0;
            int curr;
            for (int i =0;i<26;i++){
                    curr=v[i];
                    if (i==25) z=curr;
                    v[i]=prev;
                    prev=curr;
                }
                z=z%mod;
                v[0]+=z;
                v[1]+=z;
        }
        int ans=0;
        for (auto it:v){
            cout<<it<<" ";
            ans+=(it%mod);
            ans%=mod;
        }
        return ans;
    }
};

