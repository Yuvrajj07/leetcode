class Solution {
public:
    long long coloredCells(int n) {
        long long ans=1;
        long long mul=4;
        for (int i =1;i<n;i++){
            ans=ans+mul;
            mul=mul+4;
            
        }
        return ans;

        return 0;
    }
};