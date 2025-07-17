class Solution {
public:
    bool isValid(string s) {
        int v=0,c=0,n=0;
        for (int i =0;i<s.length();i++){
            if ((s[i]>=97 && s[i]<=122 )|| s[i]>=65 && s[i]<=90){
                if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'
                 || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'  ){
                    v++;
                }
                else {
                    c++;
                }
            }
            else if (s[i]>='0' && s[i]<='9') continue;
            else n++;
        }    
        cout<<c<< v<<" "<<n;
        if ( c>=1 && v>=1 && n==0 && s.length()>=3) return true;
        return false;
    }

};