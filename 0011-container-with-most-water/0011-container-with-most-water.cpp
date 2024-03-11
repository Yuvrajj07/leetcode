// BRUTE FORCE APPROACH -->

// class Solution {
// public:
//     int maxArea(vector<int>& arr) {
//         vector<int>v;
//         stack<int>st;
//         for (int i =0;i<arr.size();i++){
//             for (int j =i+1;j<arr.size();j++){
//                 int x = j-i;
//                int pushpa = x*min(arr[i],arr[j]);
//                if (st.empty() || pushpa>st.top()){
//                    st.push(pushpa);
//                }
//             }
//         }
//             int ans =st.top();
       
//       return ans;
//     }
     
// };

class Solution {
public:
    int maxArea(vector<int>& arr) {
        int i =0,j=arr.size()-1;
        int x = arr[i]*arr[j];
        int ans=0;
        while (i<j){
            // int area=min(arr[i],arr[j])*(j-i);
             int area = (std::min(arr[i],arr[j]) * (j - i));
            ans=max(ans,area);
            if (arr[i]<arr[j])i++;
            else j--; 
        }
        return ans;
    }
     
};
