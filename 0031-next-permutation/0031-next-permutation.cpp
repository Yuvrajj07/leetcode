class Solution {
public:
    void nextPermutation(vector<int>& v) {
        int idx=-1;
        for (int i=v.size()-1;i>0;i--){
            if (v[i]>v[i-1]){
                idx=i;
                break;
            }
        }
        if (idx==-1) return sort(v.begin(),v.end());
        
        // cout<<idx<<endl;
        sort(v.begin()+idx,v.end());
        for (int i =idx;i<v.size();i++){
            if (v[idx-1]<v[i]){
                swap(v[idx-1],v[i]);
                break;
            }
        }
    }
};