class Solution {
public:
    bool doesValidArrayExist(vector<int>&v) {
        vector<int>v1;
        v1.push_back(0);
        for (int i=0;i<v.size()-1;i++){
            int x=v1[i]^v[i];
            v1.push_back(x);
        }
        vector<int>v2;
        v2.push_back(1);
        for (int i=0;i<v.size()-1;i++){
            int x=v2[i]^v[i];
            v2.push_back(x);
        }
        int n=v.size()-1;
        int x1= v1[0] ^v1[n];
        int x2= v2[0] ^v2[n];
        if (v[n]==x1 || v[n]==x2) return true;
        return false;
    }
};