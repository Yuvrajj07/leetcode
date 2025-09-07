class Solution {
public:
    vector<int> threeEqualParts(vector<int>&v) {
        int c=0;
        for (auto it:v){
            if(it==1) c++;
        }
        if (c==0) return {0,2};
        cout<<"c "<<c<<endl;
        if(c%3!=0) return {-1,-1};
        int req=c/3;
        // cout<<"req "<<req<<endl;
        string s3="";
        int p3=-1,p1=-1;
        c=0; 
        for (int i =v.size()-1;i>=0;i--){
            if (v[i]==1) c++;
            s3+=to_string(v[i]);
            p3=i;
            // cout<<"s3 --> "<<s3<<" c "<< c<<" req "<<req<<endl;
            if (c==req) break;
        }
        cout<<"s3 "<<s3<<endl;
        reverse(s3.begin(),s3.end());

        // Ignore the leading zeroes 
        for (int i=0;i<v.size();i++){
            p1=i;
            if (v[i]==1) break; 
        }
        int c2=0,store_p1=p1;
        string s1="";
        while (s3!=s1){
            if (v[p1]==1) c2++;
            if (c2>req) break;
            s1+=to_string(v[p1]);
            p1++;
        }
        string s2="";
        int p2=-1,c3=0;
        for (int i=p1;i<v.size();i++){
            p2=i;
            if (v[i]==1) break;
        }
        for (int i=p2;i<v.size();i++){
            p2=i;
            if(v[i]==1) c3++;
            if (c3>req) break;
            s2+=to_string(v[i]);
            if (s3==s2) break;
        }
        cout<<s1<<" "<<s2<<" "<<s3<<endl;
        if (s1==s2 &&  s2==s3) return {p1-1,p2+1};
        return {-1,-1};
    }
};

// 1100000100000010011
// 10010001001000100100

/*
APPROACH :
--> first check if the numbers of 1 is divisible by 3 or not. if not then return {-1,-1};
--> we have to partition the string into three equal parts . which means that each part will have equal number of 1(ones).
--> now we will try to find the number which is possible by only required number of 1(ones).
--> travese from the back include all the numbers in a string till the numbers of ones (1) present in the string reaches the required   number of ones in the string.  
--> now ignore the leading zeroes because it will not impact on the values of the binary digits.
--> now traverse from the begining and  include all the charactes of the string till string s1==string s3 or the number of ones limits is reached .

*/