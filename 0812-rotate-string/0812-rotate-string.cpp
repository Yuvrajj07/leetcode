class Solution {
public:
    bool rotateString(string s, string goal) {
        for (int i =0;i<s.length();i++){
            string s1=s.substr(0,i);
            string s2= s.substr(i);
            string f="";
            f+=s2;
            f+=s1;
            if (f==goal) return true;
    }
    return false;
    }
};