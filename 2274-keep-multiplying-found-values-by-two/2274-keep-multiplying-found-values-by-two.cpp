class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,int>m;
        for (auto it: nums){
            m[it]++;
        }   
        while (m.find(original)!=m.end()){
            original*=2;
        }
        return original;
    }
};