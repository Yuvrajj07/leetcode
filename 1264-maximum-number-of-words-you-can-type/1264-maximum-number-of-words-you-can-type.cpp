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
            string d=word;
            for (int i =0;i<d.length();i++){
                if (c.find(d[i])!=c.end()){
                    ct++;
                    break;
                }
            }
            tt++;
        }
        return tt-ct;
    }
};