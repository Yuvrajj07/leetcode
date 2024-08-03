class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int >m1;
        unordered_map<int,int >m2;
        
        for (int  i=0;i<target.size();i++){
            m1[target[i]]++;
        }
        for (int  i=0;i<arr.size();i++){
            m2[arr[i]]++;
        }
        if (m1.size()!=m2.size()){
            return false;
        }

        for (auto it:m1){
            int x= it.first;
            if (m2[x]!=it.second) return false;
        }
        return true;
    }
};