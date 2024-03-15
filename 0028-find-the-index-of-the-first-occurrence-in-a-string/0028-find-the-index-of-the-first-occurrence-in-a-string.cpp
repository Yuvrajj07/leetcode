class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int ns = needle.size();

        int hs = haystack.size();
        if(ns > hs) return -1;

        for(int i=0;i<=hs-ns;i++){

            string ans = haystack.substr(i,ns);
            if(ans == needle) return i;
        }

        return -1;
    }
};