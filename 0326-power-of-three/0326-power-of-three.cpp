class Solution {
public:
    bool isPowerOfThree(int n) {
        long long sum;
      
            for (int i =1;i<n;i++){
                sum=pow(3,i);
                if (sum>=n){
                    break;
                }
        }
        if (sum==n && n>0){
            return true ;
        }
        else {
            return false;
        }
    }
};