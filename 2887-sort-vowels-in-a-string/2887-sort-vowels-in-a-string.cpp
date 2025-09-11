class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e'|| c=='i' || c=='o' || c=='u');
    }
    string sortVowels(string s) {
        multiset<char>m;
        for (int i=0;i<s.length();i++){
            if (isVowel(s[i])) {
                m.insert(s[i]);
            }
        }
        cout<<m.size()<<endl;
        for (int i =0;i<s.length();i++){
            if (isVowel(s[i])){
                char c= *m.begin();
                s[i]=c;
                m.erase(m.begin());
            }
        }
        return s;

    }
};