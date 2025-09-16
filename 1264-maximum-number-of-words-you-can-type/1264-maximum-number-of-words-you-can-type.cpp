class Solution {
public:
    int canBeTypedWords(string t, string b) {
        unordered_set<char>c;
        for (auto i:b){
            c.insert(i);
        }   
        int tt=0,ct=0;
        string word;
        stringstream s(t);
        while (s>>word){
            
            for (int i =0;i<word.length();i++){
                if (c.find(word[i])!=c.end()){
                    ct++;
                    break;
                }
            }
            tt++;
        }
        return tt-ct;
    }
};