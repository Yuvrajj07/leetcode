class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for (int i=0;i<arr.size();i++) {
            m[arr[i]]=m[arr[i]]+1;
        }
        multiset<int> mt;
        for (auto it:m){
            mt.insert(it.second);
        }
        while(k>0){
            if (mt.empty())return 0; 
            auto itr=mt.begin();
            int x=*itr; 
            if (k<x)return mt.size();
             k-=x; 
            mt.erase(itr);
        }
        return mt.size(); 
    }
};
