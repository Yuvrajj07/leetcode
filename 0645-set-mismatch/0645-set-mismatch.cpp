class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int ,int>m;
        for (int  i =0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int x,y=INT_MAX,i=1;
        for(auto it :m){
            auto z=m.find(i);
            if (z==m.end()){
                y=i;
            }
            i++;
            if (it.second >1) x=it.first;
        }
        if (y==INT_MAX) y=nums.size();
        return {x,y};

    }
};