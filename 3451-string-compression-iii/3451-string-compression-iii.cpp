class Solution {
public:
    string compressedString(string word) {
        
            string s="";
            int c=1;
        for (int i =0;i<word.length();i++){
            
            if(word[i]==word[i+1] && c<9){
                c++;
            }
            else {
                s+=to_string(c);
                s+=word[i];
                c=1;
            }
        }
        return s;

    }
};