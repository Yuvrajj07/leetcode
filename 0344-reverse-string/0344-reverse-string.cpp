class Solution {
public:
    void reverseString(vector<char>& st) {
        int s =0,e= st.size()-1;
	while (s<e){
		char temp= st[s];
		st[s]=st[e];
		st[e]=temp;
		s++;
		e--;
	}
    }
};