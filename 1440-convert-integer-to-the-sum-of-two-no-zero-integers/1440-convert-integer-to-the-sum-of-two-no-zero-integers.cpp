class Solution {
public:
bool check_zero(int t)
{
  

    while(t)
    {
        int a=t%10;
        if(a==0)
        return true;
        t=t/10;
    }
    return false;
}
    vector<int> getNoZeroIntegers(int n){
        for(int i=1;i<n;i++)
        {
            int a=i;
            int b=n-a;
            bool m=check_zero(b);
            bool n=check_zero(a);
            if(m==false && n==false)
            {
                return {a,b};
            }
        }
        return {};
    }
};