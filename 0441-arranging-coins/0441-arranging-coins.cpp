class Solution {
public:
    int arrangeCoins(int n) {
       long long  sum =0,height=0;
        for (int i =1;i<=n;i++){
            sum =  sum +i;
            if (sum>=n){
                 height = i;
                 break;
            }
        }
        if (sum ==n) return height ;
        else return height -1;
        
    }
};