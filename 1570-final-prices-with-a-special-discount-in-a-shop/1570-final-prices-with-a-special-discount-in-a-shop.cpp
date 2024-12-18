class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<pair<int, int>> st;
        vector<int> ans(prices.begin(), prices.end()); 
        st.push({prices[0], 0}); 
        for (int i = 1; i < prices.size(); i++) {
            while (!st.empty() && st.top().first >= prices[i]) {
                pair<int, int> p1 = st.top();
                st.pop();
                int val = p1.first;
                int idx = p1.second;
                ans[idx] = val - prices[i]; 
            }
            st.push({prices[i], i}); 
        }

        return ans;
    }
};



// .....................................WRONG ANSWER............................................ 






// class Solution {
// public:
//     vector<int> finalPrices(vector<int>& prices) {
//         stack<pair<int,int>>st;
//         vector<int>ans(prices.begin(),prices.end());
//         st.push({prices[0],0});
//         int i =1;
//         while (!st.empty() && i<prices.size()){
//             if (st.empty()){
//                 st.push({prices[i],i});
//                 i++;
//             }
//             else if (st.top().first>prices[i]){
//                 while(st.top().first>prices[i]){
//                     pair<int,int>p1=st.top();
//                     st.pop();
//                     int val= p1.first;
//                     int idx=p1.second;
//                     ans[idx]=prices[idx]-prices[i];
//                 }
                
//             }
//             else {
//                     st.push({prices[i],i});
//                     i++;
//                 }
//         }
//         return ans;
//     }
// };