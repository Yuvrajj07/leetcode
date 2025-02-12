class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>f1;
        vector<int>f2;
        for (auto it:queries){
            char c='z';
            string s=it;
            for(int i=0;i<s.length();i++){
                c=min(s[i],c);
            }
            int  freq=0;
            for (int i =0;i<s.length();i++){
                if (s[i]==c) freq++;
            }
            f1.push_back(freq);
        }
        for (auto it:words){
            char c='z';
            string s=it;
            for(int i=0;i<s.length();i++){
                c=min(s[i],c);
            }
            int  freq=0;
            for (int i =0;i<s.length();i++){
                if (s[i]==c) freq++;
            }
            f2.push_back(freq);
        }
        vector<int>ans;
        for (int i =0;i<f1.size();i++){
            int cnt=0;
            for (int j=0;j<f2.size();j++){
                if (f1[i]<f2[j]) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};