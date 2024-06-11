class Solution {
public:
    int sum =0;
    void solve(vector<vector<int>>&ans,vector<int>output,int k,int n,int index){
        if (output.size()==k && sum ==n){
            ans.push_back(output);
            return ;
        }
        for (int i =index;i<=9;i++){
        output.push_back(i);
            sum+=i;
            solve(ans,output,k,n,i+1);
            output.pop_back();
            sum-=i;
        
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>output;
        solve(ans,output,k,n,1);
        return ans;
    }
};