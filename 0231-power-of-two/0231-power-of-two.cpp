class Solution {
public:
    bool isPowerOfTwo(int n) {
      if(  n>0 && 2147483648%n==0 ){
          return true;
      }
      else {
          return false ;
      }
    }
};