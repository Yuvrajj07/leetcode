class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int>v(32,0);
        for (int i =0;i<c.size();i++){
            int c1 =0;
            int z= c[i];
            while (z>0){
                if(z&1==1){
                    v[c1]=v[c1]+1;
                }
                c1++;
                z=z>>1;
            }

        }
        int ans =0;
        for (auto it :v){
            ans=max(ans,it);
        }
        
        return ans;

    }
};