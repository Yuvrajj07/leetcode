// class Solution {
// public:
//     bool checkValidString(string s) {
//         int l=0,r=0,a=0;
//         for (int i=0;i<s.length();i++){
//             if (s[i]=='(')  l++;
//             else if (s[i]==')') r++;
//             else  if (s[i]=='*')a++;
//             cout<<"";
//             if (r>l && l+a<r) return false;
//             else if (r>l && l+a>=r) {
//                 int less=abs(l-r);
//                 a-=abs(l-r);
//                 l+=less;
//             }
//         }
//         cout<<s.length()<<endl;
//         cout<<l<<" "<<a<<" "<<r<<endl;
//         if (l!=r && abs(l-r)>=a) return false;
//         return true;
//     }
// };

class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0, a = 0;  // Counts for '(', ')', and '*' respectively.
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(')  
                l++;
            else if (s[i] == ')') 
                r++;
            else if (s[i] == '*') 
                a++;

            // If closing brackets exceed possible '(' + '*', it's invalid
            if (r > l + a) 
                return false;
        }
        l = 0, r = 0, a = 0;  // Reset counts for reverse pass
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s[i] == ')')  
                r++;
            else if (s[i] == '(') 
                l++;
            else if (s[i] == '*') 
                a++;

            // If opening brackets exceed possible ')' + '*', it's invalid
            if (l > r + a) 
                return false;
        }

        return true;  // If both passes are valid, return true.
    }
};
