class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int sti=0,mxlen=1;
        auto eca = [&] (int l ,int r ){
            while (l>=0 && r<n && s[r]==s[l]){
                if (mxlen<r-l+1){
                    sti=l;
                    mxlen=r-l+1;
                }
                r++;
                l--;
            }
            
        };
        for (int i =0;i<n;i++){
            eca(i,i);
            eca(i,i+1);
        }
       return s.substr(sti,mxlen);
        // return ans;

    }
};