class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums) {
        stack<int> st;
        unordered_map<int, int> m;
        for (auto num: nums) {
            while (!st.empty() && num > st.top()) {
                m[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }
        while (!st.empty()) {
            m[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int num: nums1) {
            ans.push_back(m[num]);
        }
        return ans;
    }
};