class Solution {
public:
    int peakIndexInMountainArray(vector<int>& s) {
        int z=0;
        int max =0;
    for (int i=0;i<s.size();i++){
        if (s[i]>max){
            max=s[i];
             z=i;
        }
    }  
    return z;
    }
};