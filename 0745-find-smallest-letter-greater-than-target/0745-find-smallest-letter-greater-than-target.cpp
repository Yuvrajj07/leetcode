class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char x;
        sort(letters.begin(),letters.end());
        for(int i=0;i<letters.size();i++){
            if(target<letters[i]){
                x=letters[i];
                return x;
            }
       }
         return letters[0];
    }
};