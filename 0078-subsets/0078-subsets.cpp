class Solution {
public:

    vector<vector<int>>ans;
    
    void solve(int i,vector<int>nums,vector<int>op){
        if (i==nums.size()){
            ans.push_back(op);
            return ;
        }
        op.push_back(nums[i]);
        solve(i+1,nums,op);
        op.pop_back();
        solve(i+1,nums,op);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n= nums.size();
        vector<int>op;
         solve(0,nums,op);
         return ans;
    }
};