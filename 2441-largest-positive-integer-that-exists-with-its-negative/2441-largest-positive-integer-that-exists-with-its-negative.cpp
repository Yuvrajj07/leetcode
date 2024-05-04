class Solution {
public:
    int findMaxK(vector<int>& v) {
        sort(v.begin(),v.end());
        int i =0,j=v.size()-1;
        while (i<j) {
            if (v[i]+v[j]==0){
                return v[j];
            }
            else if (v[i]+v[j]>0){
                j--;
            }
            else {
                i++;
            }
        }
        return -1;
    }

};