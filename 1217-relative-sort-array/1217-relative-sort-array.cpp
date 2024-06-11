class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        multiset<int>m;
        for (int i=0;i<arr1.size();i++){
            m.insert(arr1[i]);
        }
        vector<int>ans;
        int j=0;
        while(j<arr2.size()){
            int x= arr2[j];
            auto it = m.find(x);
            while (it!=m.end()){
                ans.push_back(x);
               m.erase(it); 
            it = m.find(x); 
            }
            j++;
        }
        if (m.size()!=0){
            for (auto it :m){
                ans.push_back(it);
            }
        }
        return ans;       
    }
};