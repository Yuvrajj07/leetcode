class Solution {
public:
    vector<int>t;
    vector<bool>used;
    void solve(vector<int>&nums,vector<vector<int>>&ans){
        if (t.size()==nums.size()) {
            ans.push_back(t);
            return ;
        }
        for (int i =0;i<nums.size();i++){
            if (used[i]) continue;
            used [i]=true;
            t.push_back(nums[i]);
            solve(nums,ans);
            t.pop_back();
            used[i]=false;
        }        
    }
    vector<vector<int>> permute(vector<int>& nums) {
     used =vector<bool>(nums.size(),false);
     vector<vector<int>>ans;
     solve(nums,ans);
     return ans;   
    }
};