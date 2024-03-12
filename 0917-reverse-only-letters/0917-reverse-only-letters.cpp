class Solution {
public:
    string reverseOnlyLetters(string s) {
        int x=0,y=s.length();
        while(x<y){
            
            if (isalpha(s[x]) && isalpha(s[y])){
                swap(s[x],s[y]);
                x++;
                y--;
            }
             if (!isalpha (s[x]))  x++;
             if (!isalpha (s[y]))  y--;

            }
            return s;
        
    }
};