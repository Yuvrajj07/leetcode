class Solution {
public:
    long long minEnd(int n, int x) {
        long long ans = x;

        for(int i = 1; i < n; i++) {
            //  cout<<ans<<" ";
            ans = (ans+1) | x;
            // cout<<ans<<" ";
        }

        return ans;
    }
};
/*

question :  we need the element x after doing the and of the entire array 

solution : so the first number will be same number itself (x).
    -->    if we need further more numbers such that the and of all the elements is x we  
           need set   bits at the same place in the every element .
    -->    so in order to set bits at the same place in every element we will set the bits
           at that particular position in the 
    -->     so we will do the OR operation of the number (X) with the number (x+1)

    */
  