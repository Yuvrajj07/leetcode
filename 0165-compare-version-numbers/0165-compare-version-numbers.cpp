class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0,j=0;
        int n1=v1.size(), n2=v2.size();
        while (i<n1 || j<n2) {
            long num1 = 0, num2 = 0;
            while (i<n1 && v1[i]!='.') {
                num1=num1*10+(v1[i]-'0');
                i++;
            }
            while (j<n2 && v2[j]!='.') {
                num2=num2*10+(v2[j]-'0');
                j++;
            }
            if (num1>num2) return 1;
            if (num1<num2) return -1;
            i++;
            j++;
        }
        return 0;
    }
};








// class Solution {
// public:
//     int compareVersion(string v1, string v2) {
//         string s1="",s2="";
//         bool b1=false,b2=false;
//         for (int i =0;i<v1.length();i++){
//             if (b1){
//                 if(v1[i]>='0' && v1[i]<='9') s1+=v1[i];
//             }
//             if (v1[i]=='.') b1=true;
//         }
//         for (int i =0;i<v2.length();i++){
//             if (b2){
//                 if(v2[i]>='0' && v2[i]<='9') s2+=v2[i];
//             }
//             if (v2[i]=='.') b2=true;
//         }
//         if (s1.empty()) s1 = "0";   // avoid stoi("") crash
//         if (s2.empty()) s2 = "0";
//         int mn=min(s1.size(),s2.size());
//         string dummy1="",dummy2="";
//         for (int i =0;i<mn;i++){
//             dummy1+=s1[i];
//             dummy2+=s2[i];
//         }
//         int n1=stoi(s1) ,n2=stoi(s2);
//         if (n1>n2) return 1;
//         else if (n1==n2) return 0;
//         else return -1;      
//     }
// };