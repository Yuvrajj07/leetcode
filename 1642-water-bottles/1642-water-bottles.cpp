class Solution {
public:
    int numWaterBottles(int tt, int ex) {
        int ans=tt;
        while (tt>=ex){
            ans+=(tt/ex);
            int re=tt%ex;
            tt/=ex;
            tt+=re;
        }
        return ans;
    }
};