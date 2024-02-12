class Solution {
public:
    int countPrimes(int n) {
        vector<bool>chk(n+1,true);
        chk[0]=chk[1]=false;
        int count=0;
        for(int i =2;i<n;i++){
            if (chk[i]) {
                count++;
            for (int j=2*i;j<n;j=j+i){
                chk[j]=0;
            }
        }
      }
        return count;
    }    
};

