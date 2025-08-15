class Solution {
public:
    bool isPowerOfFour(int n) {
        long long  ans=1;
        while (ans<n){
            ans=ans<<2;
        }
        return ans==n;

    }
};