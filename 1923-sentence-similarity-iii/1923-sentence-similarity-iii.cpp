class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1, v2;
        int idx = 0;

        // Split sentence s1 into words and store in v1
        for (int i = 0; i <= s1.length(); i++) {  
            if (i == s1.length() || s1[i] == ' ') { 
                string s = s1.substr(idx, i - idx);
                v1.push_back(s);
                idx = i + 1;
            }
        }
        
        // Split sentence s2 into words and store in v2
        idx = 0;
        for (int i = 0; i <= s2.length(); i++) {  
            if (i == s2.length() || s2[i] == ' ') { 
                string s = s2.substr(idx, i - idx);
                v2.push_back(s);
                idx = i + 1;
            }
        }

        int x = v1.size();
        int y = v2.size();
        
        // If sizes are different, swap to always work with the smaller first
        if (x > y) {
            swap(v1, v2);
            swap(x, y);
        }
        
        // Check prefix match
        int i = 0;
        while (i < x && v1[i] == v2[i]) {
            i++;
        }
        
        // Check suffix match
        int j = 0;
        while (j < x && v1[x - 1 - j] == v2[y - 1 - j]) {
            j++;
        }

        // If the sum of matched prefix and suffix words is at least the size of the smaller sentence, return true
        return i + j >= x;
    }
};














// class Solution {
// public:
//     bool areSentencesSimilar(string s1, string s2) {
//         vector<string>v1;
//         vector<string>v2;
//         int idx=0;
//        for (int i = 0; i <= s1.length(); i++) {  
//        if (i==s1.length()||s1[i]==' '){ 
//             string s = s1.substr(idx,i-idx);
//             v1.push_back(s);
//             idx = i + 1;
//        }
//     }
//             idx=0;
//        for (int i = 0; i <= s2.length(); i++) {  
//        if (i==s2.length()||s2[i]==' '){ 
//             string s = s2.substr(idx,i-idx);
//             v2.push_back(s);
//             idx = i + 1;
//     }
//        }
//        int x=v1.size();
//        int y=v2.size();
//        vector<int>ans1;
//        vector<int>ans2;
//        if (x>y){
//         int i =0,j=0;
//         while (i<s1.length()){
//             if(s1[i]==s2[j]){
//                 ans1.push_back(i);
//                 i++;
//                 j++;
//             }
//             else {
//                 i++;
//             }
//         }
//         int d=0;
//         for (int i =0;i<ans1.size()-1;i++){
//             if(ans1[i]+1!=ans1[i+1]) d++;
//         }
        

//         if (d>=2) return false;
//         }
//        else if  (x<=y){
//         int i =0,j=0;
//         while (i<s2.length()){
//             if(s1[i]==s2[j]){
//                 ans2.push_back(i);
//                 i++;
//                 j++;
//             }
//             else {
//                 i++;
//             }
//         }
//         int d=0;
//         for (int i =0;i<ans2.size()-1;i++){
//             if(ans2[i]+1!=ans2[i+1]) d++;
//         }

//         if (d>=2) return false;

//        }
//   return true;      
//     }
// };