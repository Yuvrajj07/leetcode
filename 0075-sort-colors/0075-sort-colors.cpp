class Solution {
public:
    void sortColors(vector<int>& v) {
        int o=0,z=0,t=0;
        for (auto it:v){
            if(it==1) o++;
            else if(it==2) t++;
            else z++;           
        }
        int i =0;
        while (i<v.size()){
            if (z>0){
                v[i]=0;
                z--;
            }
            else if (o>0){
                v[i]=1;
                o--;
            }
            else {
                v[i]=2;
            }
            i++;
        }
        // return v;
    }
};