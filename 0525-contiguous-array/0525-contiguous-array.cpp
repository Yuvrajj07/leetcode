class Solution {
public:
    int findMaxLength(vector<int>& v) {
     unordered_map<int,int>m;
     int s =0;
     m[0]=-1;
     int res  =0;
    for (int i =0;i<v.size();i++){
        if (v[i]==0) s++;
        else s--;
        if(m.find(s)!=m.end())
        res = max(res,i-m[s]);
        else m[s]=i;
    }
    return res;
    }
};