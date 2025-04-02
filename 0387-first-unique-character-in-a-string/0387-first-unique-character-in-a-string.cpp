class Solution {
public:
    int firstUniqChar(string s) {

        
    // aproach --> 1
    
    //     int c=0,ans=0;
    //     for (int i =0;i<s.length();i++){
    //         c=  c = count(s.begin(), s.end(), s[i]);
    //         if (c==1) {
    //         return i;
    //         break;
    //         }
    //     }
    // return -1;

    // aproach --> 2
    unordered_map<char,int>m;
    for (int i =0;i<s.length();i++){
        m[s[i]]=m[s[i]]+1;
    } 
    for (int i =0;i<s.length();i++){
        if (m[s[i]]==1){
             return i;
             break;
        }
    }

return -1;
    }
};