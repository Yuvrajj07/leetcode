class Solution {
public:
    int sti=0,mxlen=1;
    void solve(int l ,int r,string s ){
        int n = s.size();
            while (l>=0 && r<n && s[r]==s[l]){
                if (mxlen<r-l+1){
                    sti=l;
                    mxlen=r-l+1;
                }
                r++;
                l--;
            }
    }
    string longestPalindrome(string s) {
        int n = s.size();
        for (int i =0;i<n;i++){
            solve(i,i,s);
            solve(i,i+1,s);
        }
        string ans=s.substr(sti,mxlen);
       return  ans;

    }
};