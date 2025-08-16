class Solution {
public:
    int maximum69Number (int num) {
         
        int ans=0 ,chk=-1;
        vector<int>v;
        while (num>0){
            v.push_back(num%10);
            num/=10;
        }

        for (int i =v.size()-1;i>=0;i--){
            if (v[i]==6) {
                chk=i;
                break;
            }
        }

        for (int i =v.size()-1;i>=0;i--){
            if (i==chk){
                ans=ans*10+9;
            }
            else {
                ans=ans*10+v[i];
            }
        }
        return ans;
    }
};