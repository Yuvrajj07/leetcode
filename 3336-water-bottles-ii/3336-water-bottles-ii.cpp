class Solution {
public:
    int maxBottlesDrunk(int tt, int exc) {
        int ans=tt;
        int f=0,e=tt;
        while (f+e>=exc){
            ans=ans+1;
            f++;
            e=e-exc;
            exc++;
        }
        return ans;
    }
};