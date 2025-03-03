class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int size=pow(2,nums.size());
        for (int i =0;i<size;i++){
            vector<int>push;
            int x=0,j=i;

            while (j>0){
                if (j&1==1){
                    push.push_back(nums[x]);
                }
                j=j>>1;
                x++;
            }
            ans.push_back(push);
        }
        return ans;
    }
};