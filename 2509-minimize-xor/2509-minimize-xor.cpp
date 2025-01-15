class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int n1 = __builtin_popcount(num1); // Corrected method name
        int n2 = __builtin_popcount(num2); // Corrected method name

        if (n1 == n2) return num1;

        vector<int> v(32, 0); // Initialize with size 32 and fill with 0
        int i = 0;

        // Convert num1 to binary and store in vector
        while (num1 > 0) {
            v[i] = num1 % 2;
            num1 /= 2;
            i++;
        }

        if (n2 > n1) {
            // Add more 1s to match n2
            i = 0;
            while (n1 < n2 && i < 32) {
                if (v[i] == 0) {
                    v[i] = 1;
                    n1++;
                }
                i++;
            }
        } else {
            // Remove excess 1s to match n2
            i = 0;
            while (n1 > n2 && i < 32) {
                if (v[i] == 1) {
                    v[i] = 0;
                    n1--;
                }
                i++;
            }
        }

        // Convert binary vector back to integer
        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (v[i] == 1) {
                ans += (1 << i); // Use bitwise shift instead of pow
            }
        }

        return ans;
    }
};






// class Solution {
// public:
//     int minimizeXor(int num1, int num2) {
//      int n1 =num1.built__popcount(1);
//      int n2 =num2.built__popcount(1);
//      if (n1==n2) return num1;
//      vector<int>v(0,32);
//      int i =0;
//      if (n2>n1){
//         while (num1>0){
//             if (num1%2==0){
//                 v[i]=0;
//             }
//             else {
//                 v[i]=1;
//             }
//             i--;
//             num1/=2;
//         }
//         i=0
//         while (n1>0 && i>=0){
//             if (v[i]!=0){
//                 v[i]=0;
//                 n1--;
//             }
//             i--;
//         }
//         int ans=0;
//         for (int i =31;i>=0;i++){
//             if(v[i]==1){
//                 ans= ans+pow(2,i);
//             }
//         }
//         return ans ;
//      }
        
//     }
// };