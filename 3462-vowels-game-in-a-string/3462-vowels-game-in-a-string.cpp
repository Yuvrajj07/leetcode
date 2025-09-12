class Solution {
public:
    bool doesAliceWin(string s) {
     int v=0;
     for (auto it:s){
        if (it=='a' || it=='e' || it=='o' || it=='i' || it=='u') v++;
     }   
     if (v==0) return false;
     return true;
    }
};