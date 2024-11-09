#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, sign = 1;
        long result = 0;
        while (i < s.length() && s[i] == ' ') {
            i++;
        }
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // 4. Apply the sign
        return result * sign;
    }
};




// #include <bits/stdc++.h>
// class Solution {
// public:
//     int myAtoi(string s) {
//         string ans="";
//         bool z= false,neg=true;
//         int  mult =1;

//         for (int i=0;i<s.length();i++){
//             if (s[i]>='0' && s[i]<='9' ){
//                 if (s[i]=='0' && z==true){
//                     ans+="0";
//                 }
//                 else if (s[i]!='0'){
//                     ans+=s[i];
//                     z=true;
//                 }
//             neg=false;
//         }

//         else if (s[i]=='-' && neg==true){
//              mult=-1;
//         }
//         else if ((s[i]==' '  || s[i]=='+') && neg== true ){
//             // pass
//             cout<<"";
//         }
//         else{
//             break;
//         }
//     }
//     cout<<ans;
//     if (ans.length()==0) return 0;
//     long long  op=0,ret=0;
    
//     for (int i=0;i<ans.length();i++){

//         int z= ans [i]-'0';
      
//           if (op > (INT_MAX - z) / 10) {
//                 return (mult == 1) ? INT_MAX : INT_MIN;
//             }
//               op= (op*10)+z;


//     }
//     op*=mult;
//         return op;
//     }
// };