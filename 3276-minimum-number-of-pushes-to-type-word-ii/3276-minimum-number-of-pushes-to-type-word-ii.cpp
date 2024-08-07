class Solution {
public:
    void print(auto& c){
        for(int x: c) cout<<x<<", "; 
        cout<<endl;
    }
    int minimumPushes(string& word) {
        int freq[26]={0};
        for(char c: word) 
            freq[c-'a']++;
        sort(freq, freq+26, greater<int>());
        int sz=0, push=1, ans=0;
        for(; sz<26 && freq[sz]!=0; sz++){
            if (sz>=8 && sz%8==0) push++;
            ans+=freq[sz]*push;    
        }
        return ans;
    }
};

auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();





// class Solution {
// public:
//     int minimumPushes(string word) {
//         map<char,int>m;
//         for (int i =0;i<word.size();i++){
//             m[word[i]]++;           
//         }
//         map<char,int>::iterator it;
//         it=m.end();
//         // it--;
//        int  j=1,s=1,ans=0;
//         for (it;;it--){
//             ans=ans+(s*(*it).second);
//             if (j%9==0){
//                 s++;
//             }
//             j++;
//             if (it==m.begin()) break;
//         }
//         return ans;
//     }
// };