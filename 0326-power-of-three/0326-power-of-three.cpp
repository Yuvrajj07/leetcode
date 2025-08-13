class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n==1) return true;
        // if (n<0)  n*=-1;
        long long  ans=1;
        while (ans<n){
            ans*=3;
            if (ans==n) return true;
        }
        return false;
        
    }
};