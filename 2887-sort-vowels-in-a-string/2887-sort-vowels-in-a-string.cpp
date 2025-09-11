class Solution {
public:
    bool isVowel(char c) {
        c = tolower(c);
        return (c=='a' || c=='e'|| c=='i' || c=='o' || c=='u');
    }
    string sortVowels(string s) {
        multiset<char>m;
        for (int i=0;i<s.length();i++){
            if (s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
                m.insert(s[i]);
            }
            if (s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ){
                m.insert(s[i]);
            }

        }
        cout<<m.size()<<endl;
        for (int i =0;i<s.length();i++){
            if (s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ){
                char c= *m.begin();
                s[i]=c;
                m.erase(m.begin());
            }
            else  if (s[i]=='A' || s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ){
                char c= *m.begin();
                s[i]=c;
                m.erase(m.begin());
            }
            // if (isVowel(s[i])){
            //     char c= *m.begin();
            //     s[i]=c;
            //     m.erase(m.begin());
            // }

        }
        return s;

    }
};