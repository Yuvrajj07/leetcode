class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<int,int>m;
        int c=0;
        for (int i =0;i<nums.size();i++){
            if(nums[i]==0) c++;
            else {
                m[c]++;
                c=0;
            }
        }
        m[c]++;
        
        long long  ans=0;
        for (auto it :m){
            long long  x= it.first;
            long long  y= it.second;
            long long  total=(x*(x+1))/2;
            ans=ans+total*y;
            
        }
        return ans;

    }
};