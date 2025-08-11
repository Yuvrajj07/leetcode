// APPROACH :CHECK  FOR ALL THE POSSIBLE ANSWERS THAT ARE THE POWER OF 2 FROM 1 TO 2^31.
// SORT TH NUMBER EVERYTIME AND ALSO SORT THE POWER OF 2 EVERY TIME AND CHECK WEATHER THEY BOTH ARE SAME OR NOT.
// EXAMPLE =9604 
/* STEP 0-3: 1,2,4,8;
STEP 4 : POW=16 SORTED= 16;
STEP 5 : POW=32 SORTED= 23;
SAME ...  
STEP 12= 2^12=4096 SORTED=0469  N IN SORTED IS ALSO =0469 SO IT WILL RETURN TRUE
*/ 

class Solution {
public:

    string sortedDigits(int num) {
        string s = to_string(num);
        sort(s.begin(), s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string target = sortedDigits(n);
        for (int i = 0; i < 31; i++) { // 2^0 to 2^30
            if (target == sortedDigits(1 << i)) return true;
        }
        return false;
    }
};





//...............BRUTE .......................

// class Solution {
// public:

//     bool reorderedPowerOf2(int n) {
//         vector<int>d;
//         while (n>0){
//             int x=n%10;
//             n/=10;
//             d.push_back(x);
//         }
//         string chk="";
//             sort(d.begin(),d.end());
//             for (auto it:d){
//                 chk+=to_string(it);
//             }
//             vector<int>l=d;
//             int i =0;
//             if(d[0]==0){
//                 while (d[i]==0){
//                     i++;
//                 }
//                 swap(d[i],d[0]);
//             }
//             int ln=0,sn=0;
//             for (int i=0;i<d.size();i++){
//                 sn=sn*10+d[i];
//             }
//             cout<<endl;
//             for (int i=d.size()-1;i>=0;i--){
//                 ln=ln*10+l[i];
//             }   
//             cout<<sn<<" "<<ln<<endl;
//             for ( i=sn;i<=ln;i++){
//                 if (2147483648 % i==0) {
//                     cout<<i<<" ";
//                     string s1=to_string(i);
//                     sort(s1.begin(),s1.end());
//                     if (s1==chk) return true;
//                 } 
//             }
//             return false;
        
//     }
// };