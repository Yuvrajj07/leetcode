// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
//         stack<int>st;
//         // unordered_set<int>s;
//         int j=0;
//         for (int i =0;i<pushed.size();i++){
//             if(st.top()==popped[j]){
//                 st.pop();
//                 j++;
//             }
//         //    s.insert(pushed[i]);
//             st.push(pushed[i]);
//         }
//         while (!st.empty()){
//             if (st.top()==popped[j]){
//                 st.pop();
//                 j++;
//             }
//             else {
//                 break;
//             }
//         }
//         if (st.empty()) return true;
//         return false;

//     }
// };


class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;
        for (int i = 0; i < pushed.size(); ++i) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j; // Move to the next element in popped sequence
            }
        }
        return st.empty();
    }
};
