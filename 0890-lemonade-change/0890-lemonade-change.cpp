class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f=0,t=0,ans=0;
        for (int i=0;i<bills.size();i++){
            if (bills[i]==5){
                ans++;
                f++;
            }
            else if (bills[i]==10){
                if (f<=0) return false;
                ans++;
                t++;
                f--;
            }

            else  {
                if (f>=1 && t>=1){
                    ans++;
                    f-=1;
                    t-=1;
                }
                else if (f>=3){
                    ans++;
                    f-=3;
                }
                else {
                    return false;
                }
                
            }
        }
        return true;
    }
};