class Solution {
public:
    int majorityElement(vector<int>& v) {
        unordered_map<int,int>m;
        for (int i =0;i<v.size();i++){
            m[v[i]]=m[v[i]]+1;
        }
        unordered_map<int ,int >::iterator it;
        int sum =0;
        for (it=m.begin();it!=m.end();it++){
            int z=v.size()/2;
            if ((*it).second>z){
                sum = (*it).first;
            }

}        
return sum;
    }
};