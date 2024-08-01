class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (int i = 0; i < details.size(); i++) {
            string s = details[i];
            string f = s.substr(11, 2); // Get the substring from position 11 with length 2
            int z = stoi(f); // Convert the substring to an integer
            if (z > 60) ans++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int countSeniors(vector<string>& details) {
//         int ans=0;
//         for (int i=0;i<details.size();i++){
//             string  s=details[i];
//             char s1=s[11];
//             char s2=s[12];
//             string f=s+s1+s2;
//             int z=stoi(f);
//             if (z>60) ans++;
//         }
//         return ans;
//     }
// };