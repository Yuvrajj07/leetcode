class Solution {
public:
    bool isNStraightHand(vector<int>& v, int s) {
        map<int,int>m;
        for (auto it :v){
            m[it]++;
        }

        while (!m.empty()){
            int x=s;
            int prev=-1;
            if(m.size()<x) return false; 
                for (auto it:m){
                    int z= it.first;
                    if (prev==-1 || prev ==z-1){
                        m[z]--;
                        if (m[z]==0) m.erase(z);
                        prev=z;
                    }
                    else return false;
                    x--;
                    if (x==0) break;
                }
        }
        return true;
    }
};









// class Solution {
// public:
//     bool isNStraightHand(vector<int>& v, int s) {
//         int ans =1;
//         if (s==1) return true;
//         unordered_set<int>s1;
//         vector<int>an;
//         for (auto it :v){
//             s1.insert(it);
//         }
//         for (auto it :s1){
//             an.push_back(it);
//         }
//         sort(an.begin(),an.end());
//         vector<long long >v1;
//         for (int i=0;i<an.size();i++){
//             if (an[i]+1==an[i+1]){
//                 ans++;
//             }
//             else {
//                 if (ans>=s){
//                     v1.push_back(ans);
//                 }
//                    ans=1;
//             }
//         }
//         int z=0;
//         for (int i =0;i<v1.size();i++){
//             long long p1=v1[i];
//             z+=p1-s+1;
//         }
//         cout<<z<<endl;
//         if (z>=s) return true;
//         return false;
//     }
// };