class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        int k=1;  // number of operation . start with zero operation.
        while (1){
            long long  x= num1- 1ll*k*num2; 
             // if we have performed k operation then the number which is left is = (num1- k*num2) ==> and we need to check weather we can represent it in power of two or not .
            if (x<k) return -1;
             // if k is greater than the remaning number =(num1- k*num2) then it means that we cannot represent it in powerr of 2. because the min number which is power of 2 is 1 . we cannot make a number n with more than n powers of 2.
             //example -> x=4 , k=4 then it is posssibe (1+1+1+1=4) but if x=4 and k=5(k>x) then it is not possible because the minimim number we can form is(1+1+1+1+1 = 5)    
            if (k>=__builtin_popcountll(x)) return k ;

            k++; // increment k every time to check all the possibel possibilites .

        }
    }
};