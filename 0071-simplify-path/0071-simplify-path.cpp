// class Solution {
// public:
//     string simplifyPath(string s) {
//         stack<string>st;
//         string s1="",prev="";
//         bool  chk=true,sym=false;
//         for (int i =0;i<s.length();i++){
//             if(s[i]>='a' && s[i]<='z'){
//                 if(sym){
//                     st.push(s1);
//                     s1="";
//                     sym=false;
//                 }
//                 s1+=s[i];
//                 chk=true;
//             }
//             else {
//                 if (chk){
//                     st.push(s1);
//                     s1="";
//                     chk=false;
//                 }
//                 if(prev=="" || prev==s[i]){
//                     s1+=s[i];
//                     sym=true;
//                 }
//                 else {
//                     if(sym){
//                         st.push(s1);
//                         s1=s[i];
//                         prev=s[i];
//                     }
                    

//                 }

//             } 
//         }
        

//     }
// };

class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string temp;

        for (int i = 0; i <= s.size(); i++) {
            if (i == s.size() || s[i] == '/') {
                if (temp == "" || temp == ".") {
                    // Skip empty or current directory
                } else if (temp == "..") {
                    if (!st.empty()) st.pop(); // Go one directory up
                } else {
                    st.push(temp); // Valid directory name
                }
                temp = ""; // Reset for next segment
            } else {
                temp += s[i];
            }
        }

        // Construct simplified path
        string res = "";
        while (!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }

        return res == "" ? "/" : res;
    }
};


