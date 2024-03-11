class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int x = s.length();
        for (int i =0;i<x;i++){
            if (st.empty()){
                st.push(s[i]);
            }
            else if ((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']')){
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        if (st.empty()){
            return true;
        }
        else {
            return false;
        }
    }
};