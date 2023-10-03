class Solution {
public:
    bool isPerfectSquare(int n) {
        int i =1;
        int flag =0;
        while (i<=n/i){
            if (i*i==n){
                flag=1;
                break;
            }
            else {
                i++;
            }
        }
    if (flag ==1){
return true;
    }
        else {
return false;
        }
    }
};