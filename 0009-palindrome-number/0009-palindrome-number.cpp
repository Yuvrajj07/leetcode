class Solution {
public:
    bool isPalindrome(int x) {
        int s=x;
        long long n=0;
        while (x>0){
            int z= x%10;
            n=n*10+z;
            x=x/10;
        }
//        cout<<n<<endl;
        if (s>=0 && s==n ) return true ;
        else return false;
    }
};