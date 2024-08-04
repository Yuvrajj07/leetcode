class Solution {
public:
    int getSum(int a, int b) {
        while(b!=0){
            int carry=a&b;
            cout<<a<<" ";
            a=a^b;
            cout<<a<<" ";
            b=carry<<=1;
        }
        return a;
    }
};