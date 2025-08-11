class Solution {
public:
    int calPoints(vector<string>& s) {
        stack<int>st;   
        for (int i =0;i<s.size();i++){
            if (s[i]!="+" && s[i]!="D" && s[i]!="C" ){
                st.push(stoi(s[i]));
            }
            else if (s[i]=="C"){
                st.pop();
            }
            else if (s[i]=="D"){
                st.push(2*st.top());
            }
            else {
                 if (st.size() >= 2) {
                    int first = st.top(); st.pop();
                    int second = st.top();
                    st.push(first); // restore first
                    st.push(first + second);
                }
            }
        }
        int ans=0;
        while (!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};