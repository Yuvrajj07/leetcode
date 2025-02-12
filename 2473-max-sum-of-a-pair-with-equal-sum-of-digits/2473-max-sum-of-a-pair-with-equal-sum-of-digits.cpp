class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>>m;
        for (auto it:nums){
            int x= it;
            int sum=0;
            while (x>0){
                sum+=x%10;
                x=x/10;
            }
            m[sum].push_back(it);
        }
    int ans =-1;
    for (auto it :m){
        sort(it.second.begin(),it.second.end());
        int z= it.second.size();
        if(z>1){
            ans=max(ans,it.second[z-1]+it.second[z-2]);
        }
    }
        return ans;
    
    }
};