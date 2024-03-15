// class Solution {
// public:
//     vector<int> plusOne(vector<int>& v) {
//         int ans=0;
//         int x =v.size()-1;
//         if(v[x]%10!=9){
//         v[x]=v[x]+1;
//         }
      
//         else {
//             for (int i =x;i>=0;i--){
//                 if(v[i]==9){
//                    v[i]=0;
//                 }
//                 else {
//                     ans=i;
//                     break;
//                 }
            
//             }
//             v[ans]=v[ans]+1;
//             if (ans==0 && v[1]==9){
//                 v.push_back(0);
//             }
//         }
        
//         return v;
        
//     }
// };


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if( digits[digits.size()-1] <9) digits[digits.size()-1]++;
        else {
            int i = digits.size()-1 ;
            
            while(i >=0 && digits[i] == 9) {
                digits[i]= 0 ;
                i--;
            }
            if ( i < 0 ) {
                digits.insert(digits.begin(),1) ;
            }
            else {
                digits[i]++;
            }
        }
        return digits;
    }
};