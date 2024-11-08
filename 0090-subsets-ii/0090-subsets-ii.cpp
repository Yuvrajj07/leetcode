


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>v;
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        int n= 1<<(nums.size());
        for (int i =0;i<n;i++){
            int x=i;
            int j=0;
            vector<int>temp;
            while (x>0){
                if ((x&1)==1){
                    temp.push_back(nums[j]);
                }
                j++;
                x=x>>1;
            }
            s.insert(temp);
        }
        for (auto it :s){
            v.push_back(it);
        }
        return v;

    }
};