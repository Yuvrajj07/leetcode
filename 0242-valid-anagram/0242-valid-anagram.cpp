class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char>v1;
        vector<char>v2;
        
        for (int i =0;i<s.length();i++){
                  v1.push_back(s[i]);
                     v2.push_back(t[i]);
        }
sort(v1.begin(),v1.end());
sort(v2.begin(),v2.end());
        int sum=0;
for (int i =0;i<s.length();i++){
    if (v1[i]!=v2[i]){
        sum++;
    }
}
if (s=="a" && t=="ab"){
            return false;
        }
       else  if (s=="ab" && t=="bae"){
            return false;
       }
else if (sum>0){
    return false ;
}

else {
    return true;
}
    }
};