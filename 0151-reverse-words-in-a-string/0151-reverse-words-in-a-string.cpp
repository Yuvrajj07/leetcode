class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans = "";
        
        while (ss >> word) {  // Extract words while ignoring extra spaces
            if (!ans.empty()) ans = " " + ans;  // Add space before previous words
            ans = word + ans;  // Reverse word order
        }
        
        return ans;
    }
};






// class Solution {
// public:
//     string reverseWords(string s) {
//         int n=s.length();
//         string ans="";
//         string s1="";
//         for (int i=n-1;i>=0;i--){
//             if (s[i]==' '){
//                 reverse(s1.begin(),s1.end());
//                 ans+=s1;
//                 if (s1!=""){
//                 ans+=' ';
//                 }
//                 s1="";
                
//             }
//             else if (s[i]!=' '){
//                 s1+=s[i];
//             }
//         }
//         int sp=0,chk=false;
//         for (int i=ans.length()-1;i>=0;i--){
//             if (s[i]==' '){
//                 sp++;
//                 chk=true;
//             }
//             else break;
//         }
//         ans=ans.substr(0,ans.length()-sp-1);

//         reverse(s1.begin(),s1.end());
//         ans+=s1;
                
//         return ans;
//     }
// };

