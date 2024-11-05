class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x1=0,x2=0,y1=0,y2=0;
        for (int i =0;i<s1.length();i++){
            if (s1[i]!=s2[i]){
                if (s1[i]=='x') x1++;
                else y1++;
            }
        }
        if ((x1+y1)%2!=0) return -1;
        return (x1+1)/2 +(y1+1)/2; 
//         for (auto it :s1){
//             if (it=='x') x1++;
//             else y1++;
//         }
//         for (auto it :s2){
//             if (it=='x') x2++;
//             else y2++;
//         }
//         int X=x1+x2;
//         int Y=y1+y2;
//         if (X%2!=0 || Y%2!=0) return -1;
//         int ans =0;
//         int i =0;
//         for (int i =0;i<s1.length();i++){
//             if(s1[i]!=s2[i]){
//                 ans++;
//                 for(int j=i+1;j<s1.length();j++){
//                     if(s1[j]!=s2[j] && s1[i]==s2[j]){
//                         char c1=s1[i];
//                         s1[i]=s2[j];
//                         s2[j]=c1;
//                     }
//                 }
//             }
//         }
// cout<<s1<<" "<<s2<<endl;
// return ans;
        
    }
};