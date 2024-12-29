class Solution {
public:
    int trailingZeroes(int n) {

        int ans=0;
        while (n>=5){
            n/=5;
            ans+=n;
            
        }
        return ans;

//...........................WRONG ANSWER\U0001f601 .....................................    
        // the number of zeroes from :
        // 1-4     --> 0;
        // 5-9     --> 1;
        // 10-14   --> 2
        // 15-19   --> 3
        // 20-24   --> 4
        // return floor(float(n/5));


    }
};