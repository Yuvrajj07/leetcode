class Solution {
public:
    string reverseParentheses(string s) {
        stack<pair<char,int>>st;
        for (int i =0;i<s.length();i++){
            if (st.empty()){
                st.push({'(',i});
            }
            else if (s[i]=='('){
                st.push({'(',i});
            }
            else if (s[i]==')'){
                int a =st.top().second;
                int  b=i;
                while (a<b){
                    swap(s[a],s[b]);
                    a++;
                    b--;
                }
                st.pop();
            }
        }
        string  ans="";
        for (int i =0;i<s.length();i++){
            if (s[i]!='(' && s[i]!=')') ans+=s[i];
        }
        return ans;
        
    }
};