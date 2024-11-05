class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int o=0,z=0;
        for (int i =0;i<s.length();i++){
            if (s[i]=='1') o++;
            else z++;
        }
        string s1="";
        for (int i=0;i<o-1;i++){
            s1+='1';
        }
        for (int i=0;i<z;i++){
            s1+='0';
        }
        s1+='1';
        return s1;
    }
};