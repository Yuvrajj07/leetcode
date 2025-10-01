class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int>v1;
        for (auto it :nums){
            v1.push_back(it);
        }
        while (v1.size()!=1){
            vector<int>v2;
            for (int i=0;i<v1.size()-1;i++){
                int x=v1[i]+v1[i+1];
                v2.push_back(x%10);
            }
            v1=v2;
        }   
        return v1[0];
             
    }
};