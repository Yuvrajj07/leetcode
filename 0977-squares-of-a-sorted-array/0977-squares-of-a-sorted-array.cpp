// class Solution {
// public:
//     vector<int> sortedSquares(vector<int>& v) {
//       vector<int>ans;
//       int neg =0,pos=0;
//       bool zero=false;
//       for (int i=0;i<v.size();i++){
//         if (v[i]==0) {
//             zero=~zero;
//         }
//       if (v[i]<0){
//           neg=i;
//       }
//       if (v[i]>0) {
//           pos=i;
//           break;
//       }
//     }
//     if (zero) ans.push_back(0);
//       int x=v.size();
//       while(neg>=0 && pos<x){
//           if(abs(v[neg])<v[pos]){
//               ans.push_back(v[neg]*v[neg]);
//               neg--;
//           }
//           else {
//               ans.push_back(v[pos]*v[pos]);
//               pos++;
//           }
         
//       }
//        while (neg>=0){
//               ans.push_back(v[neg]*v[neg]);
//               neg--;
//           }
//           while (pos<x){
//               ans.push_back(v[pos]*v[pos]);
//               pos++;
//           }
    

//           return ans;
//     }


// };
class Solution {
public:
    vector<int> sortedSquares(vector<int>& v) {
        vector<int> ans;
        int neg = 0, pos = 0;
        bool zero = false;

        while (pos < v.size() && v[pos] < 0) pos++;
        neg = pos - 1;

    

        // Add the squared values in sorted order
        while (neg >= 0 && pos < v.size()) {
            if (v[neg] * v[neg] < v[pos] * v[pos]) {
                ans.push_back(v[neg] * v[neg]);
                neg--;
            } else {
                ans.push_back(v[pos] * v[pos]);
                pos++;
            }
        }

        // Add remaining squared values if any
        while (neg >= 0) {
            ans.push_back(v[neg] * v[neg]);
            neg--;
        }
        while (pos < v.size()) {
            ans.push_back(v[pos] * v[pos]);
            pos++;
        }

      

        return ans;
    }
};
