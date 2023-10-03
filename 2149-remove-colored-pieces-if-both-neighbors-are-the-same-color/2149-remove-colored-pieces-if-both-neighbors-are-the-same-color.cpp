class Solution {
public:
    bool winnerOfGame(string s) {
        int alice=0,bob=0;
        for (int i=1;i<s.length()-1;i++){
            if (s[i]=='A' && s[i+1]=='A'&& s[i-1]=='A') {
                alice++;
                }
            if (s[i]=='B' && s[i+1]=='B'&& s[i-1]=='B') {
                bob++;
                
                }
            
        }
        return alice>bob;

    }
};