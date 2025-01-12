class Solution {
public:
    bool canBeValid(string s, string locked) {
        if (s.length() % 2 != 0) return false; // Length must be even for valid parentheses

        int openBalance = 0, closeBalance = 0;

        // Left to right pass
        for (int i = 0; i < s.length(); ++i) {
            if (locked[i] == '0' || s[i] == '(') {
                openBalance++;
            } else {
                openBalance--;
            }

            if (openBalance < 0) return false; // Too many closing parentheses
        }

        // Right to left pass
        for (int i = s.length() - 1; i >= 0; --i) {
            if (locked[i] == '0' || s[i] == ')') {
                closeBalance++;
            } else {
                closeBalance--;
            }

            if (closeBalance < 0) return false; // Too many opening parentheses
        }

        return true; // All checks passed
    }
};

// class Solution {
// public:
//     bool canBeValid(string s, string locked) {
//         int i =0,c=0;
//         if (s.length()%2!=0) return false;
//         while (i<s.length()){
//             if (s[i]=='0') c++;
//             else if (s[i]=='1'){
//                 if (s[i]=='(' && s[i+1]!=')'){
//                     if (c<=0) return false;
//                     else c--;
//                 } 
//                 else if (s[i]==')' && s[i-1]!='(' ) {
//                     if (c<=0) return false;
//                     else c--;
//                 }
                 
//             }
//             i++;
//         }
//         return true;

//     }
// };
