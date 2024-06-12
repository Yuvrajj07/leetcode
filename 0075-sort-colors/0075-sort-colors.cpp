class Solution {
public:
    void sortColors(vector<int>& v) {
        int z=0,o=0,t=0;
        for (int i =0;i<v.size();i++){
            if (v[i]==1) o++;
            else if (v[i]==2) t++;
            else z++;
        }
        // cout<<o<<t<<z<<endl;
         for (int i =0;i<v.size();i++){
        if (i<z) v[i]=0;
        else if (i>=z && i<o+z)  v[i]=1;
        else  v[i]=2;
    }

    }
};