class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        vector<int>output;
        vector<vector<int>>ans;
        int index=0;
        solve(nums,output,ans,index);
        return ans;
    }
   void  solve(vector<int>nums,vector<int>output,vector<vector<int>>&ans,int index){
        if (index>=nums.size()){
            ans.push_back(output);
            return ;
        }
        // exculde the element
        solve(nums,output,ans,index+1);
        
        //include the element 
        output.push_back(nums[index]);
        solve(nums,output,ans,index+1);
    }
    
};