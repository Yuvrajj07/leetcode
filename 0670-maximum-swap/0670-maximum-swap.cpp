class Solution {
public:
    int maximumSwap(int num) {
        // Convert the number into a vector of digits
        vector<int> digits;
        int original = num;
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end()); // Digits are in reverse order, so reverse them
        
        // Record the last occurrence of each digit (0-9)
        vector<int> last(10, -1);
        for (int i = 0; i < digits.size(); i++) {
            last[digits[i]] = i;
        }
        
        // Try to find the first place where we can make a swap for a larger number
        for (int i = 0; i < digits.size(); i++) {
            // Check if there's a larger digit later in the array
            for (int d = 9; d > digits[i]; d--) {
                if (last[d] > i) {
                    // Swap the current digit with the larger digit found later
                    swap(digits[i], digits[last[d]]);
                    
                    // Convert the digits back to the number
                    int result = 0;
                    for (int digit : digits) {
                        result = result * 10 + digit;
                    }
                    return result; // Return the largest possible number after the swap
                }
            }
        }
        return original;
    }
};






// class Solution {
// public:
//     int maximumSwap(int num) {
//         if (num<10)return num;
//         vector<int>v;
//         while (num>0){
//             int x=num%10;
//             v.push_back(x);
//             num=num/10;
//         }
//         reverse(v.begin(),v.end());
//         int mx=v[0],idx=0;
//         for (int i =0;i<v.size();i++){
//             if (mx<v[i]){
//                 mx=v[i];
//                 idx=i;
//             }
//         }
//         int s1=0,s2=0;;
//         for (int i=0;i<v.size();i++){
//             if(v[i]<mx){
//                 s1=i;
//                 break;
//             }
//         }
//         int m1x=v[s1];
//         for (int i=s1;i<v.size();i++){
//             if (m1x<v[i]){
//                 m1x=v[i];
//                 s2=i;
//             }
//         }
//         swap(v[s1],v[s2]);
//         for (int i =0;i<v.size();i++){
//             cout<<v[i];
//         }
//         return 1;
        
//     }
// };