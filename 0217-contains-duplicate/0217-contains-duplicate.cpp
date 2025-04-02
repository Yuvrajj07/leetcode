class Solution {
public:
    bool containsDuplicate(vector<int>& v) {
        unordered_map<int,int>m;
        for (int i =0;i<v.size();i++){
            m[v[i]]=m[v[i]]+1;
        }
    unordered_map<int,int>:: iterator it;
    int sum=0;
    for (it=m.begin();it!=m.end();it++){
        if ((*it).second>1){
            sum++;
        }
    }
    if (sum>0){
        return true;
    }
    else {
       return  false;
    }
    }
};